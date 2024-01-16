// Copyright EdrSantandr


#include "UI/Widget/EssentialUserWidget.h"

void UEssentialUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
