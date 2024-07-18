#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle {
	friend class LblShape;
	int m_height;
	int m_width;
	//methods:
	void draw();
	void getSpecs();
	Rectangle();


};

#endif //RECTANGLE_H