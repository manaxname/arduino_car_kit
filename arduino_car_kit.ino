#include "ServoDriveController.h";

ServoDriveController *driveCtrl;

void setup()
{
	driveCtrl = new ServoDriveController(2, 3, 5, 4);
}

void loop()
{
	delay(5000);

	driveCtrl->MoveForward();
	delay(1000);
	driveCtrl->MoveStop();
	delay(1000);

	driveCtrl->MoveBack();
	delay(1000);
	driveCtrl->MoveStop();
	delay(1000);

	driveCtrl->TurnRight();
	delay(1000);
	driveCtrl->MoveStop();
	delay(1000);

	driveCtrl->TurnLeft();
	delay(1000);
	driveCtrl->MoveStop();
	delay(1000);
}
