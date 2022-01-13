#pragma once
struct Coordinates {
    int x;
    int y;
};

class Object {
private:
    Coordinates coordinates;
    int distance = 0;

public:

    Object() : coordinates({ 0,0 }) {};
    Object(Coordinates newCoordinates, int newDistance, bool choice) : coordinates(newCoordinates),
        distance(newDistance) {};
    Object(int x, int y, int newDistance, bool choice) : coordinates({ x, y }),
        distance(newDistance) {};

    Coordinates GetCoordinates() const { return coordinates; }
    void SetCoordinates(int x, int y) { coordinates.x = x; coordinates.y = y; }
    void SetCoordinates(Coordinates newCoordinates) { coordinates = newCoordinates; }

    int GetDistance() const { return distance; }
    void SetDistance(int newDistance) { distance = newDistance; }

};

