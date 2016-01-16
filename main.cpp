#include <iostream>
#include <png++/png.hpp>
#include <random>

int main(int argc, char ** argv)
{
	if (argc != 3)
	{
		return 1;
	}

	std::mt19937 engine(std::random_device{}());
	std::uniform_int_distribution<int> disp(0, 3);
	std::uniform_int_distribution<int> rand(0, 196);

	png::image<png::rgba_pixel> src(argv[1]);
	png::image<png::rgba_pixel> dst(src.get_width(), src.get_height());

	for (int y = 0; y < src.get_height(); ++y)
	{
		for (int x = 0; x < src.get_width(); ++x)
		{
			auto p = src.get_pixel(x, y);
			int v = (p.red + p.green + p.blue + rand(engine) + rand(engine) + rand(engine)) / 6;
			dst[y][x] = png::basic_rgba_pixel<unsigned char>(v, v, v, 255);
		}
	}
	dst.write(argv[2]);
}

