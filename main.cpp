#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <iostream>
using namespace std;

struct Point{float x;float y;char Name;};
float distance(Point A, Point B); // return distance between point A and B (use Pifagor's Theorem)
float perimeter(Point Array[4]); // return distance perimeter usind function distance 4 times
float area(Point Array[4]);  // return area using Gauss's area formula or use Geron formaula for two triangles ABC + ACD
QString printQuad(Point Arr[4]); // and also to QString

int main()
{
    cout << "To calculate perimeter and area of a quadrilateral, enter name and coordinates of four points, which will be vertexes of the quadrilateral: "
         << endl;
    string cyphers [4] = {"first ", "second", "third ", "fourth"}; // Строка для подставления слов во фразы в цикле.
    Point quadOne[4];

    for (int i=0; i<4; i++){
        cout << "Enter name of the " << cyphers [i] << " point: ";
        cin >> quadOne[i].Name;
        cout << "Enter X-coordinate: \t";
        cin >> quadOne[i].x;
        cout << "Enter Y-coordinate: \t";
        cin >> quadOne[i].y;
    }   cout << endl;

    for (int i=0; i<4; i++){
        cout << "Name of the " << cyphers [i] << " point is " << quadOne[i].Name << "\t with coordinates: [" << quadOne[i].x << " : " << quadOne[i].y << ']' << endl;
    }   cout << endl;

    qDebug() << printQuad(quadOne);
    QString qsRetVal = "Have perimeter %1 and area %2";
    float perim,ar;
    perim = perimeter(quadOne);
    ar = area(quadOne);
    qsRetVal = qsRetVal.arg(perim,0,'f',2).arg(ar,0,'f',3);
    qDebug() << qsRetVal;
}

QString printQuad(Point Arr[4])
{
    QString qsRetVal = "Quadrilateral with points: ";
    QString qsTemp;
    Point curPoint;
    for (int i=0; i<4; i++){
        qsTemp = "%1[%2;%3] ";
        curPoint = Arr[i];
        qsTemp=qsTemp.arg(curPoint.Name).arg(curPoint.x).arg(curPoint.y);
        qsRetVal.append(qsTemp);
    }
    return qsRetVal;
}

float distance(Point A, Point B)
{
    return sqrt( (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) );
}

float perimeter(Point Array[4])
{
    Point A[5];
    int i=0;
    for (; i<4; i++)A[i]=Array[i];
    A[i]=Array[0];
    float ret=0;
    for (i=0; i<4; i++) ret+=distance(A[i],A[i+1]);
    return ret;
}

float area(Point Array[4])
{
    Point A[5];
    int i=0;
    for (; i<4; i++)A[i]=Array[i];
    A[4]=Array[0];
    float ret = 0.0;

    for (i=0; i<4; i++) {  // Цикл добавлен для применения формулы Гаусса
        ret = ret + (A[i].x * A[i+1].y) - (A[i].y * A[i+1].x);
    };
    return fabs(ret/2.0);
}
