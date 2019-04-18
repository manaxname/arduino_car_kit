#pragma once
class ServoDriveController
{
private:
	int MoveRightSideForward, MoveRightSideBack, MoveLeftSideBack, MoveLeftSideForward;

public:

	ServoDriveController(int rFrwd, int rBack, int lFrwd, int lBack)
	{
		MoveRightSideForward = rFrwd;
		MoveRightSideBack = rBack;
		MoveLeftSideForward = lFrwd;
		MoveLeftSideBack = lBack;
		pinMode(MoveRightSideForward, OUTPUT);
		pinMode(MoveRightSideBack, OUTPUT);
		pinMode(MoveLeftSideBack, OUTPUT);
		pinMode(MoveLeftSideForward, OUTPUT);
	}

	//  ---------------- MOVING -------------------------
	void MoveForward()
	{
		MoveStop();
		digitalWrite(MoveRightSideForward, HIGH);
		digitalWrite(MoveLeftSideForward, HIGH);
	}

	void MoveBack()
	{
		MoveStop();
		digitalWrite(MoveRightSideBack, HIGH);
		digitalWrite(MoveLeftSideBack, HIGH);
	}

	void TurnRight()
	{
		MoveStop();
		digitalWrite(MoveRightSideBack, HIGH);
		digitalWrite(MoveLeftSideForward, HIGH);
	}

	void TurnLeft()
	{
		MoveStop();
		digitalWrite(MoveRightSideForward, HIGH);
		digitalWrite(MoveLeftSideBack, HIGH);
	}

	void MoveStop()
	{
		digitalWrite(MoveRightSideForward, LOW);
		digitalWrite(MoveRightSideBack, LOW);
		digitalWrite(MoveLeftSideForward, LOW);
		digitalWrite(MoveLeftSideBack, LOW);
	}

	//  ================= MOVING ========================
};
