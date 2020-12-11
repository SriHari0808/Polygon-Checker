#include <stdio.h>
#include <math.h>


typedef struct {

    double x;
    double y;

}point;

int analyzeRectangle(point a, point b, point c, point d) {

    int ab_x = b.x - a.x;
    int ab_y = b.y - a.y;
    int cd_x = c.x - d.x;
    int cd_y = c.y - d.y;
      
    //determine if ab//cd.
    if (ab_x == 0 || cd_x == 0) {
        if (ab_x != cd_x) {
            return 0;
        }
    }

    else {
        if (ab_y / ab_x != cd_y / cd_x) {
            return 0;
        }
    }
    
    //determine if ab=cd
    if (ab_y * ab_y + ab_x * ab_x != cd_y * cd_y + cd_x * cd_x) {
        return 0;
    }

    //determine if ab¡Íac
    int ac_y = c.y - a.y;
    int ac_x = c.x - a.x;

    if (ab_x == 0) {
        if (ac_y != 0)
            return 0;
    }

    else if (ac_x == 0) {
        if (ab_y != 0)
            return 0;
    }

    else if ((ac_y / ac_x) * (ab_y / ab_x) != -1) {
        return 0;
    }

    return 1;
}

int Perimeter(point a, point b, point c, point d) {

    double ab = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    double ac = sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y));
    double cd = sqrt((c.x - d.x) * (c.x - d.x) + (c.y - d.y) * (c.y - d.y));
    double db = sqrt((d.x - b.x) * (d.x - b.x) + (d.y - b.y) * (d.y - b.y));
    printf_s("The perimeter is: %.3f\n", ab + ac+ cd+ db);
    
    return 0;
}

int Area(point a, point b, point c) {
    double ab = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    double ac = sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y));
    printf_s("The area is: %.3f\n", ab * ac);

    return 0;
}