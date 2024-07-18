#ifndef LINE_H
#define LINE_H
class Line {
	friend class LblShape;
	int m_length;
	//methods
	void draw();
	void getSpecs();
	Line();

};

#endif //LINE_H