#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point start;
    Point end;
} Line;

double line_length(Line *a) {
    double dx = a->end.x - a->start.x;
    double dy = a->end.y - a->start.y;
    return sqrt(dx*dx + dy*dy);
}

int is_parallel(Line *a, Line *b) {
    double slope_a = (a->end.y - a->start.y) / (a->end.x - a->start.x);
    double slope_b = (b->end.y - b->start.y) / (b->end.x - b->start.x);
    return (slope_a == slope_b);
}

int is_perpendicular(Line *a, Line *b) {
    double slope_a = (a->end.y - a->start.y) / (a->end.x - a->start.x);
    double slope_b = (b->end.y - b->start.y) / (b->end.x - b->start.x);
    return (slope_a * slope_b == -1);
}

int main() {
    Line my_line1 = { {0, 0}, {10, 10} };
    Line my_line2 = { {0, 5}, {5, 0} };

    double len1 = line_length(&my_line1);

    printf("Line 1 length: %lf\n", len1);

    if (is_parallel(&my_line1, &my_line2)) {
        printf("Line 1 is parallel to Line 2.\n");
    } else {
        printf("Line 1 is not parallel to Line 2.\n");
    }

    if (is_perpendicular(&my_line1, &my_line2)) {
        printf("Line 1 is perpendicular to Line 2.\n");
    } else {
        printf("Line 1 is not perpendicular to Line 2.\n");
    }

    return 0;
}
