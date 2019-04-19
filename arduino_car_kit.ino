#include "ServoDriveController.h";

servo_drive_controller *drive_ctrl;

void setup()
{
	drive_ctrl = new servo_drive_controller(2, 3, 5, 4);
}

void loop()
{
	delay(5000);

	drive_ctrl->move_forward();
	delay(1000);
	drive_ctrl->move_stop();
	delay(1000);

	drive_ctrl->move_back();
	delay(1000);
	drive_ctrl->move_stop();
	delay(1000);

	drive_ctrl->turn_right();
	delay(1000);
	drive_ctrl->move_stop();
	delay(1000);

	drive_ctrl->turn_left();
	delay(1000);
	drive_ctrl->move_stop();
	delay(1000);
}
