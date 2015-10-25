package org.salesman;

import java.io.IOException;
import org.salesman.algo.Population;
import org.salesman.entity.Towns;

public class Entrypoint {

	public static void main(String[] args) {
		Towns towns = null;

		try {
			towns = new Towns(Salesman.FILE_PATH);
		} catch (IOException e) {
			System.out.println(e.toString());
			System.exit(-1);
		}
		
		double min = 10000;
		long iteration = 10000000;
		for(long i = 0; i < iteration; i++) {
			Population a = new Population(1000, false);
			a.genesis(towns);
			a.selectionAndReproductionAndMutation();
			a.selectionAndReproductionAndMutation();
			a.selectionAndReproductionAndMutation();
			a.selectionAndReproductionAndMutation();
			
			if ((a.getMin() < min)) {
				min = a.getMin();
				System.out.println(min + "[" + i + "] : " + a.getItineraryWithCost(min));
			}
		}
		System.out.println("done");
	}

}
