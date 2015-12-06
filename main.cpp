#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
ifstream f("date.txt");
ofstream g("infasuratoare.out");
int n,i,elements;
struct punct{double x,y;}v[120120],rez[120120];
bool ff(punct a , punct b) {if(a.x!=b.x)
                            return a.x<b.x;
                        else
                            return a.y<b.y;
                        }
double E(punct p2, punct p1, punct p)
{
    return p2.x*p1.y + p1.x*p.y + p.x*p2.y - p.x*p1.y - p2.y*p1.x - p2.x*p.y;
}

int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>v[i].x>>v[i].y;
    sort(v+1,v+n+1,ff);
    rez[1].x=v[1].x,rez[2].x=v[2].x,rez[1].y=v[1].y,rez[2].y=v[2].y;
    elements=2;
    for(i=3;i<=n;i++)
    {
        while(E(rez[elements-1],rez[elements],v[i])<=0 && elements>1)
            elements--;

        rez[++elements]=v[i];
    }
    rez[++elements]=v[n-1];
    for(i=n-2;i>=1;i--)
    {
        while(E(rez[elements-1],rez[elements],v[i])<=0 && elements>1)
            {elements--;
            //cout<<E(rez[elements-1],rez[elements],v[i])<<endl;
            }
//        elements++;
        rez[++elements]=v[i];
    }
    elements--;
    cout<<elements<<endl;
    for(i=1;i<=elements;i++)
        cout<<fixed<<setprecision(6)<<rez[i].x<<" "<<rez[i].y<<endl;
}
