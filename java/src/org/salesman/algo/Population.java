package org.salesman.algo;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Random;

import org.salesman.Salesman;
import org.salesman.entity.Town;
import org.salesman.entity.Towns;

public class Population {
	private ArrayList<Itinerary> itineraries = null;
	private boolean verbose = false;
	private int numberOfTowns;

	public Population(int numberOfItineraries) {
		this(numberOfItineraries, false);
	}

	public Population(int numberOfItineraries, boolean verbose) {
		this.itineraries = new ArrayList<Itinerary>(numberOfItineraries);
		this.verbose  = verbose;
	}

	public void genesis(Towns towns) {
		this.numberOfTowns = towns.numberOfTowns();

		for(int i = 0; i < towns.numberOfTowns(); i++) {
			this.itineraries.add(this.populate(towns));
		}
	}

	private Itinerary populate(Towns towns) {
		int numberOfTowns = towns.numberOfTowns();
		Itinerary itinerary = new Itinerary(numberOfTowns);
		int i = 0;
		//Populate one itinerary:
		do {
			int index = new Random().nextInt(numberOfTowns);
			Town next = towns.get(index);

			if (!itinerary.contains(next)) {
				itinerary.add(next);
				i++;
			}
		}while(i < numberOfTowns);

		this.validate();
		return itinerary;
	}

	public ArrayList<Double> getCosts() {
		ArrayList<Double> costs = new ArrayList<Double>(this.itineraries.size());
		for (Itinerary iti : this.itineraries) {
			costs.add(new Double(iti.getCost()));
		}
		return costs;
	}

	public void showCosts() {
		for (Itinerary iti : this.itineraries) {
			DecimalFormat df = new DecimalFormat("0.0");
			String str = df.format(iti.getCost());

			System.out.println(str);
		}
	}

	public void selectionAndReproductionAndMutation() {
		int selected = 1 + new Random().nextInt(this.itineraries.get(0).size()-1);

		this.selection(selected);
		this.validate();
		if (this.verbose) System.out.println("Selection \t min: " + this.getMin());

		this.reproduction(selected);
		this.validate();
		if (this.verbose) System.out.println("Reproduction \t min: " + this.getMin());

		this.mutation();
		this.validate();
		if (this.verbose) System.out.println("Mutation \t min: " + this.getMin());
	}

	private void validate() {
		for (Itinerary iti : this.itineraries) {
			if(iti.size() != this.numberOfTowns) {
				System.err.println(iti.size() + " :: " + iti.toString());
			}
			iti.noDoublons();
		}
	}

	public void showMin() {
		System.out.println("Minimum:" + this.getMin());
	}

	public Itinerary getItineraryWithCost(double cost) {
		Itinerary ret = null;
		int i = 0;
		do{
			if (this.itineraries.get(i).getCost() == cost)
				ret = this.itineraries.get(i);
			i++;
		}while(ret == null);
		return ret;
	}

	public double getMin() {
		double min = this.itineraries.get(0).getCost();
		for (Itinerary iti : this.itineraries) 	min = (iti.getCost() < min) ? iti.getCost() : min;

		return min;
	}

	private void mutation() {
		for (Itinerary iti : this.itineraries) {
			int mutation = new Random().nextInt(101);
			if (mutation > Salesman.MUTATION_PROBABILITY) {
				iti.mutate();
			}	
		}
	}

	private void selection(int selected) {
		double cost = this.itineraries.get(selected).getCost();
		ArrayList<Itinerary> orderedItineraries = new ArrayList<Itinerary>(this.itineraries.size());
		for (Itinerary iti : this.itineraries) {
			if(iti.getCost() <= cost) {
				orderedItineraries.add(0, iti);
			} else {
				int end = orderedItineraries.size() - 1;
				if (orderedItineraries.size() == 0) {
					end = 0;
				}
				orderedItineraries.add(end, iti);
			}
		}
		this.itineraries = orderedItineraries;
	}

	private void reproduction(int selected) {
		for(int i = selected; i < this.itineraries.size(); i++) {
			int breakPoint = new Random().nextInt(this.itineraries.size());

			Itinerary father = this.itineraries.get(new Random().nextInt(selected));
			Itinerary mother = this.itineraries.get(new Random().nextInt(selected));
			Itinerary son = this.itineraries.get(i);

			Itinerary.reproduction(breakPoint, father, mother, son);
		}
		
	}
}
