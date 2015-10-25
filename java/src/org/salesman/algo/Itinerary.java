package org.salesman.algo;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Random;

import org.salesman.entity.Town;

public class Itinerary {
	private ArrayList<Town> itinerary = null;
	private double cost = 0;


	public Itinerary(int size) {
		this.itinerary = new ArrayList<Town>(size);
	}

	public double add(Town next) {
		this.itinerary.add(next);
		
		if(this.itinerary.size() != 1) {
			Town current = this.itinerary.get(this.itinerary.size()-2);
			this.cost += Town.distance(current, next);
		}
		
		return this.cost;
	}

	public int size() {
		return this.itinerary.size();
	}

	public ArrayList<Town> getItinerary() {
		return this.itinerary;
	}

	public double getCost() {
		return this.cost;
	}

	public boolean contains(Town town) {
		return this.itinerary.contains(town);
	}

	public static void reproduction(int breakPoint, Itinerary father, Itinerary mother, Itinerary son) {
		son.itinerary = new ArrayList<Town>(father.size());

		for(int i = 0; i < breakPoint; i++) {
			son.itinerary.add(father.itinerary.get(i));
		}

		int i = 0;
		do{
			Town t = mother.getItinerary().get(i);
			if (!son.itinerary.contains(t)) {
				son.itinerary.add(t);
			}
			i++;
		}while(son.itinerary.size() < father.itinerary.size());
		son.updateCost();
	}

	private void updateCost() {
		this.cost = 0;
		for (int i = 1; i < this.itinerary.size()-1; i++) {
			Town a = this.itinerary.get(i);
			Town b = this.itinerary.get(i+1);
			this.cost += Town.distance(a, b);
		}
	}

	private Collection<? extends Town> subList(int i, int j) {
		return this.itinerary.subList(i, j);
	}

	public void mutate() {
		int indexA = new Random().nextInt(this.itinerary.size()-1);
		int indexB = 0;
		do {
			indexB = new Random().nextInt(this.itinerary.size()-1);
		} while(indexB == indexA);

		Town townA = this.itinerary.get(indexA);
		Town townB = this.itinerary.get(indexB);

		if(indexA < indexB) {
			this.itinerary.remove(indexB);
			this.itinerary.remove(indexA);
		} else {
			this.itinerary.remove(indexA);
			this.itinerary.remove(indexB);			
		}

		this.itinerary.add(indexB, townA);
		this.itinerary.add(indexA, townB);

		this.updateCost();

	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		for (Town t : this.itinerary) {
			sb.append(t.getName() + " ");
		}
		return sb.toString();
	}

	public void noDoublons() {
		for (int i = 0; i < this.itinerary.size(); i++) {
			for (int j = (i+1); j < this.itinerary.size(); j++) {
				String nameA = this.itinerary.get(i).getName();
				String nameB = this.itinerary.get(j).getName();
				if (nameA.equals(nameB)) {
					System.err.println(nameB + " is twice present!");
				}
			}
		}
	}
}
