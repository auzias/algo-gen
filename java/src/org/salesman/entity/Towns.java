package org.salesman.entity;

import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files; 
import java.nio.file.Path;
import java.nio.file.Paths;
import java.text.DecimalFormat;
import java.util.List;
import java.util.ArrayList;

import org.salesman.Salesman;


public class Towns {
	private ArrayList<Town> towns = null;
	private double[][] distances = null;

	public Towns(String filepath) throws IOException {
		List<String> townsStr = this.readFile(filepath);
		
		this.fillUpTowns(townsStr);

		//this.calculatedistances(townsStr.size());
	}

	private List<String> readFile(String filepath) throws IOException {
		//Create the path:
		Path path = Paths.get(filepath);
		//Create the charset of the file:
		Charset cs = Charset.forName(Salesman.CS);
		//Read the whole file:
		return Files.readAllLines(path, cs);
	}

	private void fillUpTowns(List<String> townsStr) {
		//Create the ArrayList with the right capacity:
		this.towns = new ArrayList<>(townsStr.size());
		//Fill up the ArrayList: 
		for (String townLine : townsStr) {
			//Parse the line
			String[] line = townLine.split(" ");

			//Create the town:
			String name = line[2];
			int x = Integer.parseInt(line[0]);
			int y = Integer.parseInt(line[1]);
			Town town = new Town(x, y, name);

			//Add the town:
			this.towns.add(town);
		}
	}

	private void calculatedistances(int arraySize) {
		//Calculate the distances:
		this.distances = new double[arraySize][arraySize];
		for(int row = 0; row < arraySize; row++) {
			for(int column = 0; column < (arraySize); column++) {
				double distance = 0;
				if (row != column) {
					Town a = this.towns.get(row);
					Town b = this.towns.get(column);
					distance = Town.distance(a, b) ;
				}
				this.distances[row][column] = distance;
				this.distances[column][row] = distance;
			}
		}
	}

	public int numberOfTowns() {
		return this.towns.size();
	}

	public void showDistances() {
		for(int row = 0; row < this.distances.length; row++) System.out.print(row + "\t");
		
		System.out.println();

		for(int row = 0; row < this.distances.length; row++) {
			System.out.print(row + "\t");
			for(int column = 0; column < this.distances.length; column++) {
				double distance = this.distances[row][column];
				DecimalFormat df = new DecimalFormat("0.0");
				String str = df.format(distance);
				System.out.print( str + "\t");
			}
			System.out.println();
		}
	}

	public void showTowns() {
		for (Town town : this.towns) {
			System.out.println(town.toString());
		}
	}

	public Town get(int index) {
		return this.towns.get(index);
	}
}
