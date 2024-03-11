#include "Canvas.h"
#include "cmath"
#include "iostream"
Canvas::Canvas(int width, int height) {
	this->canvas = new char* [height];
	for (int i = 0; i < height; i++) {
		this->canvas[i] = new char[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			this->canvas[i][j] = ' ';
		}
	}
	this->lin = height;
	this->col = width;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < this->lin; i++) {
		for (int j = 0; j < this->col; j++) {
			int dist = sqrt(pow(i - y, 2) + pow(j - x, 2));
			std::floor(dist);
			if (dist == ray) {
				this->canvas[i][j] = ch;
			}
		}
	}

}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < this->lin; i++) {
		for (int j = 0; j < this->col; j++) {
			int dist = sqrt(pow(i - y, 2) + pow(j - x, 2));
			std::floor(dist);
			if (dist <= ray) {
				this->canvas[i][j] = ch;
			}
		}
	}

}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	for (int i = 0; i < this->lin; i++) {
		for (int j = 0; j < this->col; j++) {
			if ((j == left && i>=bottom && i<= top) ||
				(j == right && i >= bottom && i <= top) ||
				(i == top && j>=left && j<=right) ||
				(i == bottom && j>=left && j<=right)) {
				this->canvas[i][j] = ch;
			}
		}
	}

}


void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for (int i = 0; i < this->lin; i++) {
		for (int j = 0; j < this->col; j++) {
			if ((j >= left && j<=right && i >= bottom && i <= top) ||
				(i >= bottom && i<=top && j >= left && j <= right)) {
				this->canvas[i][j] = ch;
			}
		}
	}

}

void Canvas::SetPoint(int x, int y, char ch) {
	this->canvas[x][y] = ch;
}

void Canvas::Print() {
	for (int i = 0; i < this->lin; i++) {
		for (int j = 0; j < this->col; j++) {
			std::cout << this->canvas[i][j];
		}
		std::cout << '\n';
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	int D = 2 * dy - dx;
	int y = y1;
	for (int x = x1; x <= x2; x++) {
		this->canvas[x][y] = ch;
		if (D > 0) {
			y++;
			D = D - 2 * dx;
		}
		D += 2 * dy;
	}
}

void Canvas::Clear() {
	for (int i = 0; i < this->lin; i++) {
		for (int j = 0; j < this->col; j++) {
			this->canvas[i][j] = ' ';
		}
	}
}

Canvas::~Canvas() {
	for (int i = 0; i < this->lin; i++) {
		delete[] this->canvas[i];
	}
	delete[] this->canvas;
}