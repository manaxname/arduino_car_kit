#pragma once

class servo_drive_controller
{
	int move_right_side_forward_;
	int move_right_side_back_;
	int move_left_side_back_;
	int move_left_side_forward_;
	const int ShimMax = 255;
	int CurrentSpeed = 0;

public:

	servo_drive_controller(const int r_frwd, const int r_back, const int l_frwd, const int l_back)
	{
		move_right_side_forward_ = r_frwd;
		move_right_side_back_ = r_back;
		move_left_side_forward_ = l_frwd;
		move_left_side_back_ = l_back;
		pinMode(move_right_side_forward_, OUTPUT);
		pinMode(move_right_side_back_, OUTPUT);
		pinMode(move_left_side_back_, OUTPUT);
		pinMode(move_left_side_forward_, OUTPUT);
	}

	//  ---------------- MOVING -------------------------
	void move_forward() const
	{
		move_stop();
		digitalWrite(move_right_side_forward_, HIGH);
		digitalWrite(move_left_side_forward_, HIGH);
	}

	void move_back() const
	{
		move_stop();
		digitalWrite(move_right_side_back_, HIGH);
		digitalWrite(move_left_side_back_, HIGH);
	}

	void turn_right() const
	{
		move_stop();
		digitalWrite(move_right_side_back_, HIGH);
		digitalWrite(move_left_side_forward_, HIGH);
	}

	void turn_left() const
	{
		move_stop();
		digitalWrite(move_right_side_forward_, HIGH);
		digitalWrite(move_left_side_back_, HIGH);
	}

	void move_stop() const
	{
		digitalWrite(move_right_side_forward_, LOW);
		digitalWrite(move_right_side_back_, LOW);
		digitalWrite(move_left_side_forward_, LOW);
		digitalWrite(move_left_side_back_, LOW);
	}

	//  ================= MOVING ========================
};
