package org.salesman.entity;

import java.awt.Point;
import java.awt.geom.Point2D;

public class Town {
	private Point p = null;
	private String name = null;

	public Town(int x, int y, String name) {
		this.p = new Point(x, y);
		this.name = name;
	}

	public static double distance(Town a, Town b) {
		double x1 = (double) a.getPoint().getX();
		double y1 = (double) a.getPoint().getY();
		double x2 = (double) b.getPoint().getX();
		double y2 = (double) b.getPoint().getY();

		return Point2D.distance(x1, y1, x2, y2);
	}

	private Point getPoint() {
		return this.p;
	}

	public String getName() {
		return this.name;
	}

	@Override
	public String toString() {
		return this.name + " (" + this.p.getX() + "," + this.p.getY() + ")";
	}

	@Override
	public boolean equals(Object o) {
		Town t = (Town)o;
		return this.p.equals(t.p);
	}
}
