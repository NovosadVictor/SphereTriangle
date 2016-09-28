#include <iostream>
#include <vector>



int main()
{
	int N;
	double max1 = 0;
	double max2 = 0;
	double maxX = 0;
	double max_X = 0;
	std::vector<double> X;
	std::vector<double> Y;
	std::vector<double> _X;
	std::cin >> N;
	while(N > 0)
	{
		double x,y;
		std::cin >> x >> y;
		if (y == 0)
			    _X.push_back(x);
		if ((y != 0) && (X.empty() || (!X.empty() && x != X.front() && y != Y.front())))
		{
			X.push_back(x);
			Y.push_back(y);
		}
		--N;
	}
	size_t count = 0;
	while (count < _X.size())
	{
		for (size_t j = 0; j < _X.size(); ++j)
		{
			if ((j > count) && _X[j] > 0 && _X[count] > 0)
				if (abs(_X[j] - _X[count]) > maxX)
					maxX = abs(_X[j] - _X[count]);
			if ((j > count) && _X[j] < 0 && _X[count] < 0)
				if (abs(_X[j] - _X[count]) > max_X)
					max_X = abs(_X[j] - _X[count]);
		}
		count++;
	}
	for (size_t i = 0; i < Y.size(); ++i)
	{
		if ((X[i] > 0) && abs(Y[i] * maxX) > max1)
			max1 = abs(Y[i] * maxX);
		if ((X[i] < 0) && abs(Y[i] * max_X) > max2)
			max2 = abs(Y[i] * max_X);
	}
	if (max1 > max2)
	    printf("%.4f", max1 / 2);
	else
		printf("%.4f", max2 / 2);
	system("pause");
	return 0;
}

