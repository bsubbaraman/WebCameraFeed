#include "SWebCameraImage.h"



SWebCameraImage::SWebCameraImage() {
	bCanTick = true;
}


void SWebCameraImage::Tick( const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime ) {
	if ( videoGrabber.IsValid() && videoGrabber->isFrameNew() ) {
		UTexture* texture = videoGrabber->getTexture();
		Brush.SetResourceObject(texture);
		Brush.ImageSize.X = videoGrabber->getWidth();
		Brush.ImageSize.Y =  videoGrabber->getHeight();
		Image = &Brush;
		Invalidate(EInvalidateWidget::LayoutAndVolatility);
	}
}

void SWebCameraImage::SetVideoGrabber(TSharedPtr<VideoGrabber> videoGrabber) {
	this->videoGrabber = videoGrabber;
}
