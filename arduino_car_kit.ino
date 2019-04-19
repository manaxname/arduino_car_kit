#include "ServoDriveController.h"

servo_drive_controller *drive_ctrl;

void setup()
{
	drive_ctrl = new servo_drive_controller(2, 3, 5, 4);
}

void loop()
{
	delay(5000);

	drive_ctrl->set_speed(255, 255);
	delay(1000);
	drive_ctrl->set_speed(155, 155);
	delay(1000);

	drive_ctrl->set_speed(155, 55);
	delay(1000);
	drive_ctrl->set_speed(55, 55);
	delay(1000);

	drive_ctrl->set_speed(55, 155);
	delay(1000);
	drive_ctrl->set_speed(155, 155);
	delay(1000);

	drive_ctrl->set_speed(255, 255);
	delay(1000);
	drive_ctrl->set_speed(0, 0);
	delay(1000);
}
