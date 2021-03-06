#pragma once

#include "rhoban_geometry/point.h"

namespace rhoban_geometry
{

class Ellipse {
private:
  Point origin;
  rhoban_utils::Angle theta;//Angle from x-axis to m axis
  double m;
  double n;// n <= m
public:
  Ellipse(): origin(), theta(), m(1), n(1) {}
  Ellipse(const Point & p, const rhoban_utils::Angle & axisAngle,
          double bigAxisLength, double smallAxisLength) {
    origin = p;
    theta = axisAngle;
    m = bigAxisLength;
    n = smallAxisLength;
  }
  Ellipse(const Ellipse & e) : origin(e.origin),
                               theta(e.theta),
                               m(e.m),
                               n(e.n) {}

  Point getCenter() const { return origin;}
  double getBigRadius() const { return m;}
  double getSmallRadius() const { return n;}
  rhoban_utils::Angle getAngle() const { return theta;}
};

}
