#include <iostream>

using namespace std;


class GeoShape
{
    protected:
        double dimension1;
        double dimension2;

    public:
        /// dimension1 setter and getter
        void setDimension1(double _dimension1){
            dimension1=_dimension1;
        }
        double getDimension1(){
            return dimension1;
        }

        /// dimension1 setter and getter
        void setDimension2(double _dimension2){
            dimension2=_dimension2;
        }
        double getDimension2(){
            return dimension2;
        }

        /// constructors
        GeoShape()
        {
            cout<<"Shape default constructor\n";
            dimension1=dimension2=0;
        }
        GeoShape(double _dim1,double _dim2)
        {
            cout<<"Shape parametrized constructor\n";
            dimension1=_dim1;
            dimension2=_dim2;
        }

        /// destructor
        ~GeoShape(){
            cout<<"Shape destructor\n";
        };
};

class Rect:public GeoShape
{

    public:

    /// constructor
    Rect(){
        cout<<"Rectangle default constructor\n";
    }
    Rect(double d1,double d2):GeoShape(d1,d2)
    {
        cout<<"Rectangle parametrized constructor\n";
    }

    /// destructor
    ~Rect(){
        cout<<"Rectangle destructor\n";
    }
    double rectangleArea()
    {
        cout<<"Rectangle destructor\n";
        return dimension1*dimension2;
    }

};

class Square:protected Rect
{
    public:

    /// dimension setter and getter
    void setDimension(int d){
        dimension1=dimension2=d;
    }
    int getDimension(){
        return dimension1;
    }

    /// constructor
    Square(){
        cout<<"Square default constructor\n";
    }
    Square(double d):Rect(d,d)
    {
        cout<<"Square parametrized constructor\n";
    }

    /// destructor
    ~Square(){
        cout<<"Square destructor\n";
    }
    double rectangleArea()
    {
        return dimension1*dimension2;
    }
};

class Triangle:public GeoShape
{
    public:

    /// constructor
    Triangle(){
        cout<<"Triangle default constructor\n";
    }
    Triangle(double b,double h):GeoShape(b,h){
        cout<<"Triangle parametrized constructor\n";
    }
    double triangleArea()
    {
        return 0.5*dimension1*dimension2;
    }
};
class Circle:public GeoShape
{
    public:
        /// dimension1 setter and getter
        void setDimension1(double _dimension1){
            dimension1= dimension2=_dimension1;
        }
        double getDimension1(){
            return dimension1;
        }

        /// dimension1 setter and getter
        void setDimension2(double _dimension2){
            dimension1=dimension2=_dimension2;
        }
        double getDimension2(){
            return dimension2;
        }

        Circle(){
            cout<<"Circle default constructor\n";
        }
        Circle(double r):GeoShape(r,r){
            cout<<"Circle parametrize constructor\n";
        }
        double circleArea()
        {
            return 3.14*dimension1*dimension2;
        }
};

int main()
{
    Circle circle(10);
    cout<<"Circle area: "<<circle.circleArea()<<endl;

    Rect rectangle(4,5);
    cout<<"Rectangle area: "<<rectangle.rectangleArea()<<endl;

    Triangle triangle(3,4);
    cout<<"Triangle area: "<<triangle.triangleArea()<<endl;

    Square square(10);
    cout<<"Square area: "<<square.rectangleArea()<<endl;


    return 0;
}
