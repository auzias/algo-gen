package org.salesman;

import java.io.IOException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

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
		
		

        ExecutorService executor = Executors.newFixedThreadPool(5);
		
		long exp = 1000;
		long iteration = 100;
		int numberOfThread = 50;
		for(int thread = 0; thread < numberOfThread; thread++, iteration*=2) {
			Experience e = new Experience(exp, iteration, towns, thread);
			Thread t = new Thread(e);
			executor.execute(t);
		}
        executor.shutdown();
        while (!executor.isTerminated());
        System.out.println("Finished all threads");
	}

}
