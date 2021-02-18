#include <iostream>

using namespace std;


class Point{
    private:
        int x;
        int y;

    public:
        /// x setter and getter
        void setX(int _x){
            cout<<"point x setter\n";
            this->x = _x;
        }
        int getX(){
            cout<<"point x getter\n";
            return x;
        }

        /// y setter and getter
        void setY(int _y){
            cout<<"point y setter\n";
            this->y = y;
        }
        int getY(){
            cout<<"point y getter\n";
            return y;
        }

        /// constructors
        Point(){
            cout<<"point default constructor\n";
            x = y = 0;
        }
        Point(int _x, int _y){
            cout<<"point parametrize constructor\n";
            this->x = _x;
            this->y = _y;
        }
        Point(const Point &old){
            cout<<"point copy constructor\n";
            this->x = old.x;
            this->y = old.y;
        }

        /// destructor
        ~Point(){
            cout<<"point destructor\n";
        }

        /// equal operator
        Point& operator=(const Point & right)
        {
            this->x = right.x;
            this->y = right.y;
            return *this;
        }


        /// print
        void printPoint()
        {
            cout<<"( "<<x<<" , "<<y<<" )"<<endl;
        }
};

class Shape
{
    protected :
        int color;
    public:
        /// color getter and setter
        void setColor(int _color){
            cout<<"Shape color setter\n";
            this->color = _color;
        }
        int getColor(){
            cout<<"Shape color getter\n";
            return color;
        }
        Shape(){
            cout<<"Shape default constructor\n";
            color=0;
        }
        Shape(int _color){
            cout<<"point parametrize constructor\n";
            color=_color;
        }
        ~Shape(){
            cout<<"Shape destructor\n";
        }
        Shape(const Shape &old){
            cout<<"Line copy constructor\n";
            this->color = old.color;

        }

        virtual void draw()=0;
};


class Line: public Shape{
    private:
        Point p1;
        Point p2;

    public:
        /// point1 setter and getter
        void setPoint1(Point _p1){
            cout<<"line point1 setter\n";
            this->p1 = _p1;
        }
        Point getPoint1(){
            cout<<"line point1 getter\n";
            return p1;
        }

        /// point2 setter and getter
        void setPoint2(Point _p2){
            cout<<"line point2 setter\n";
            this->p2 = _p2;
        }
        Point getPoint2(){
            cout<<"line point2 getter\n";
            return p2;
        }

        /// constructors
        Line(){
            cout<<"Line default constructor\n";
        }
        Line(int x1, int y1, int x2, int y2, int _color): p1(x1,y1), p2(x2,y2),Shape(_color)
        {
            cout<<"Line parametrize constructor with x & y\n";
        }
        Line(Point point1, Point point2, int _color): p1(point1), p2(point2),Shape(_color)
        {
            cout<<"Line parametrize constructor with points\n";
        }
        Line(const Line &old){
            cout<<"Line copy constructor\n";
            this->p1 = old.p1;
            this->p2 = old.p2;
            this->color = old.color;
        }

        /// destructor
        ~Line(){
            cout<<"Line destructor\n";
        }

        /// print
        void draw() override
        {
            cout<<"\nLine Details:\ncolor: "<<color<<"\nstart point: ";
            p1.printPoint();
            cout<<"end point: ";
            p2.printPoint();
        }

};


class Rect: public Shape{
    private:
        Point p1;
        Point p2;

    public:
        /// point1 setter and getter
        void setPoint1(Point _p1){
            cout<<"Rectangle point1 setter\n";
            this->p1 = _p1;
        }
        Point getPoint1(){
            cout<<"Rectangle point1 getter\n";
            return p1;
        }

        /// point2 setter and getter
        void setPoint2(Point _p2){
            cout<<"Rectangle point2 setter\n";
            this->p2 = _p2;
        }
        Point getPoint2(){
            cout<<"Rectangle point2 getter\n";
            return p2;
        }

        /// constructors
        Rect(){
            cout<<"Rectangle default constructor\n";
        }
        Rect(int x1, int y1, int x2, int y2, int _color): p1(x1,y1), p2(x2,y2), Shape(_color){
            cout<<"Rectangle parametrize constructor with x & y\n";
        }
        Rect(Point point1, Point point2, int _color): p1(point1), p2(point2), Shape(_color) {
            cout<<"Rectangle parametrize constructor with points\n";
        }
        Rect(const Rect &old){
            cout<<"Rectangle copy constructor\n";
            this->p1 = old.p1;
            this->p2 = old.p2;
            this->color = old.color;
        }

        /// destructor
        ~Rect(){
            cout<<"Rectangle destructor\n";
        }

        /// print
        void draw() override
        {
            cout<<"\nRectangle Details:\ncolor: "<<color<<"\nstart point: ";
            p1.printPoint();
            cout<<"end point: ";
            p2.printPoint();
        }

};


class Circle: public Shape{
    private:
        Point center;
        int radius;

    public:
        /// center setter and getter
        void setCenter(Point _center){
            cout<<"Circle center setter\n";
            this->center = _center;
        }
        Point getCenter(){
            cout<<"Circle center getter\n";
            return center;
        }

        /// radius getter and setter
        void setRadius(int _radius){
            cout<<"Circle radius setter\n";
            this->radius = _radius;
        }
        int getRadius(){
            cout<<"Circle radius getter\n";
            return radius;
        }

        /// constructors
        Circle(){
            cout<<"Circle default constructor\n";
            radius = 0;
        }
        Circle(int x, int y, int _radius, int _color): center(x,y),Shape(_color){
            cout<<"Circle parametrize constructor with x & y\n";
            radius = _radius;
        }
        Circle(Point _center, int _radius, int _color): center(_center),Shape(_color) {
            cout<<"Circle parametrize constructor with points\n";
            radius = _radius;
        }
        Circle(const Circle &old){
            cout<<"Circle copy constructor\n";
            this->center = old.center;
            this->radius = old.radius;
            this->color = old.color;
        }

        /// destructor
        ~Circle(){
            cout<<"Circle destructor\n";
        }

        /// print
        void draw() override
        {
            cout<<"\nCircle Details:\ncolor: "<<color<<"\nradius: "<<radius<<"\nstart point: ";
            center.printPoint();
        }

};


class Triangle: public Shape{
    private:
        Point p1;
        Point p2;
        Point p3;

    public:
        /// point1 setter and getter
        void setPoint1(Point _p1){
            cout<<"Triangle point1 setter\n";
            this->p1 = _p1;
        }
        Point getPoint1(){
            cout<<"Triangle point1 getter\n";
            return p1;
        }

        /// point2 setter and getter
        void setPoint2(Point _p2){
            cout<<"Triangle point2 setter\n";
            this->p2 = _p2;
        }
        Point getPoint2(){
            cout<<"Triangle point2 getter\n";
            return p2;
        }

        /// point3 setter and getter
        void setPoint3(Point _p3){
            cout<<"Triangle point3 setter\n";
            this->p3 = _p3;
        }
        Point getPoint3(){
            cout<<"Triangle point3 getter\n";
            return p3;
        }

        /// constructors
        Triangle(){
            cout<<"Triangle default constructor\n";
        }
        Triangle(int x1, int y1, int x2, int y2, int x3, int y3, int _color): p1(x1,y1), p2(x2,y2), p3(x3,y3),Shape(_color){
            cout<<"Triangle parametrize constructor with x & y\n";
        }
        Triangle(Point point1, Point point2, Point point3, int _color): p1(point1), p2(point2), p3(point3) ,Shape(_color){
            cout<<"Triangle parametrize constructor with points\n";
        }
        Triangle(const Triangle &old){
            cout<<"Triangle copy constructor\n";
            this->p1 = old.p1;
            this->p2 = old.p2;
            this->p3 = old.p3;
            this->color = old.color;
        }

        /// destructor
        ~Triangle(){
            cout<<"Triangle destructor\n";
        }

        /// print
        void draw() override
        {
            cout<<"\nTriangle Details:\ncolor: "<<color<<"\npoint1: ";
            p1.printPoint();
            cout<<"point2: ";
            p2.printPoint();
            cout<<"point3: ";
            p3.printPoint();
        }

};


class Picture
{
    Shape **shapePtr;
    int shapeSize;

    public:
    /// shape setter
    void setShapes(Shape** _shapePtr,int _shapeSize)
    {
        shapePtr = _shapePtr;
        shapeSize = _shapeSize;
    }

    /// constructors
    Picture()
    {
        shapePtr = NULL;
        shapeSize = 0;
    }
    Picture (Shape** _shapePtr,int _shapeSize)
    {
        shapePtr = _shapePtr;
        shapeSize = _shapeSize;
    }

    void paint()
    {
        for(int i  = 0; i < shapeSize; i++)
        {
            shapePtr[i]->draw();
        }
    }
};


int main()
{


    Point p1(1,2);
    Point p2(3,4);

    Line larr[2]={Line(1,2,3,4,5),Line(6,7,8,9,10)};
    Rect rarr[3]={Rect(1,2,3,4,5),Rect(6,7,8,9,10),Rect(p1, p2, 55)};
    Triangle tarr(1,2,3,4,6,7,5);
    Circle carr[4]={Circle(1,2,3,4),Circle(6,7,8,9),Circle(p1, 30, 55), Circle(2,6,4,3)};

    Shape *pictureShape[10] = {larr,&larr[1],&rarr[0],&rarr[1],&rarr[2],&tarr,&carr[0],&carr[1],&carr[2],&carr[3]};

    Picture picture;
    picture.setShapes(pictureShape,10);

    cout<<"\n\nPaint picture: ";
    picture.paint();
    cout<<endl<<endl;

    picture.setShapes(NULL,0);

    return 0;
}
