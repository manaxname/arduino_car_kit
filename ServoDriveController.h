#pragma once

class servo_drive_controller
{
	int move_right_side_forward_;
	int move_right_side_back_;
	int move_left_side_back_;
	int move_left_side_forward_;
	int current_right_speed_ = 0;
	int current_left_speed_ = 0;

	const int speed_max_ = 255;
	const int speed_change_value_ = 45;

	void moving() const
	{
		digitalWrite(move_right_side_forward_, LOW);
		digitalWrite(move_right_side_back_, LOW);
		digitalWrite(move_left_side_forward_, LOW);
		digitalWrite(move_left_side_back_, LOW);
		if (current_right_speed_ < current_left_speed_)
		{
			delay(speed_max_ - current_left_speed_);
			digitalWrite(move_left_side_forward_, HIGH);
			delay(current_left_speed_ - current_right_speed_);
			digitalWrite(move_right_side_forward_, HIGH);
			delay(current_left_speed_);
		}
		else if (current_right_speed_ > current_left_speed_)
		{
			delay(speed_max_ - current_right_speed_);
			digitalWrite(move_right_side_forward_, HIGH);
			delay(current_right_speed_ - current_left_speed_);
			digitalWrite(move_left_side_forward_, HIGH);
			delay(current_right_speed_);
		}
		else
		{
			delay(speed_max_ - current_right_speed_);
			digitalWrite(move_right_side_forward_, HIGH);
			digitalWrite(move_left_side_forward_, HIGH);
			delay(current_right_speed_);
		}
	}

	void change_speed(int expected_right, int expected_left)
	{
		if (current_right_speed_ != expected_right)
		{
			if (expected_right > current_right_speed_)
			{
				if (current_right_speed_ + speed_change_value_ > speed_max_)
				{
					current_right_speed_ = speed_max_;
				}
				else
				{
					current_right_speed_ += speed_change_value_;
				}
			}
			else
			{
				if (current_right_speed_ - speed_change_value_ <= 0)
				{
					current_right_speed_ = 0;
				}
				else
				{
					current_right_speed_ -= speed_change_value_;
				}
			}
		}
		if (current_left_speed_ != expected_left)
		{
			if (expected_left > current_left_speed_)
			{
				if (current_left_speed_ + speed_change_value_ > speed_max_)
				{
					current_left_speed_ = speed_max_;
				}
				else
				{
					current_left_speed_ += speed_change_value_;
				}
			}
			else
			{
				if (current_left_speed_ - speed_change_value_ <= 0)
				{
					current_left_speed_ = 0;
				}
				else
				{
					current_left_speed_ -= speed_change_value_;
				}
			}
		}
	}

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

	void set_speed(int r_speed, int l_speed)
	{
		if (r_speed > speed_max_)
			r_speed = speed_max_;
		if (l_speed > speed_max_)
			l_speed = speed_max_;
		while (current_left_speed_ != l_speed && current_right_speed_ != r_speed)
		{
			change_speed(r_speed, l_speed);
			moving();
		}
	}
};
