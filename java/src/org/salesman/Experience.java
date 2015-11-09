package org.salesman;

import org.salesman.algo.Population;
import org.salesman.entity.Towns;

public class Experience implements Runnable {

	private long exp;
	private long iteration;
	private Towns towns;
	private int id;

	public Experience(long exp, long iteration, Towns towns, int id) {
		this.exp = exp;
		this.iteration = iteration;
		this.towns = towns;
		this.id = id;
	}
	
	@Override
	public void run() {
		double min = 5000;

		for(long i = 0; i < exp; i++) {
			Population a = new Population(1000, false);
			a.genesis(towns);
			for(long j = 0; j < iteration; j++)
					a.selectionAndReproductionAndMutation();
			
			if ((a.getMin() < min)) {
				min = a.getMin();
				System.out.println("Exp#" + this.id + "(" + this.exp + "," + this.iteration + "):" + min + " " + a.getItineraryWithCost(min));
			}
		}
	}
}
