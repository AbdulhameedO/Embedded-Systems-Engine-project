#include <stdio.h>
#include <iostream>
char req1()
{
	char flag = 0;
	printf("Please choose what you want to be done: \n");
	printf("a. Turn on the vehicle engine \n");
	printf("b. Turn off the vehicle engine \n");
	printf("c. Quit the system\n");
	scanf(" %c", &flag);
	std::cin >> flag;
	return flag;
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	bool ac = 0, eng = 0;
	char flag, traffic = 0;
	float rtemp = 0, etemp = 0;
	int speed = 0;
	while (true)
	{
		flag = req1();
		if (flag == 'c')
			return 0;

		while (flag == 'b')
		{
			flag = req1();
			if (flag == 'c')
				return 0;
			else if (flag == 'a')
				break;
		}

		printf("Sensors set menu: \n");
		printf("a. Turn off the engine\n");
		printf("b. Set the traffic light color. \n");
		printf("c. Set the room temperature (Temperature Sensor) \n");
		printf("d. Set the engine temperature (Engine Temperature Sensor) \n");
		scanf(" %c", &flag);
		std::cin >> flag;
		if (flag == 'a')
			continue;
		if (flag == 'b')
		{
			printf("Input traffic light data:");
			scanf(" %c", traffic);
			std::cin >> traffic;
			if (traffic == 'G')
				speed = 100;
			else if (traffic == 'O')
				speed = 30;
			else
				speed = 0;

		}
		if (flag == 'c')
		{
			printf("Input room temperature:");
			scanf(" %c", &rtemp);
			std::cin >> rtemp;
			if (rtemp < 10)
			{
				rtemp = 20;
				ac = 1;
			}
			else if (rtemp > 30)
			{
				ac = 1;
				rtemp = 20;
			}
		}

		if (flag == 'd')
		{
			printf("Input engine temperature:");
			scanf(" %c", &etemp);
			std::cin >> etemp;
			if (etemp < 100)
			{
				etemp = 125;
				eng = 1;
			}
			else if (etemp > 150)
			{
				etemp = 125;
				eng = 1;
			}
		}
		if (speed == 30)
		{
			if (!ac)
			{
				rtemp = rtemp * (5 / 4) + 1;
				ac = 1;
			}
			if (!eng)
			{
				etemp = etemp * (5 / 4) + 1;
				eng = 1;
			}
		}

		printf("Engine is ON\n");
		if (ac)
			printf("AC is ON\n");
		else
			printf("AC is OFF\n");

		printf("Speed is:%d \nRoom Temperature :%f \n", speed, rtemp);

		if (eng)
			printf("Controller is ON \n");
		else
			printf("Controller is OFF \n");

		printf("Engine Temperature :%f \n\n", etemp);
	}
	return 0;

}