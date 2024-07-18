#ifndef SHAPE_H
#define SHAPE_H
class Shape {
	//Methods
	virtual ~Shape() = default; //no implementation is needed
	virtual void draw(std::ostream& os) = 0;//This pure virtual function can not modify the current object.
	void getSpecs(std::istream& is);
	std::ostream& operator<<(std::ostream& os);
	std::istream& operator>>(std::istream& is);
};

#endif //SHAPE_H