Hospital Patient Queue System

A Data Structures & Algorithms semester project built in C++ to simulate a hospital patient queue using priority queues, hash tables, and sorting/searching algorithms.

---------------------------------------------------------------------------

Objective

To design and implement a hospital patient queue management system that:

 Automatically assigns unique patient IDs
 Prioritizes patients based on severity
 Allows doctors to manage and serve patients efficiently
 Stores and sorts patient checkup history


Features

 Priority queue (Max-Heap) for urgent patients
 Hash table with linear probing for quick lookups
 Patient check-in, checkup, and tracking
 Sorting by age, name, or checkup time
 Search by name or patient ID


Data Structures & Algorithms

| Component      | Technique        					      |                     Purpose             |
|----------------|------------------------------------------------------------|-----------------------------------------|
| Priority Queue | Max-Heap         					      | Serve critical patients first           |
| Hash Table     | Linear Probing   					      | Fast ID-based lookup                    |
| Sorting        | Quick, Select, Insertion Sort 			      | Flexible record sorting    		|
| Searching      | Linear, Binary   					      | Quick searches in patient history       |


Sample Menu Operations

1. Add New Patient
2. View/Serve Next Patient
3. Search by ID or Name
4. Sort Checked Patients
5. View Doctor Info


Contributors – Group 7

| Name	            | Roll No           |
|------------------|-------------------|
| Armughan Naeem	  | 4822-FOC/BSSE/F23 |
| Abdullah Shakeel	| 4793-FOC/BSSE/F23 |
| Usama Javed	     | 4829-FOC/BSSE/F23 |
| Syed Hussain Ali	| 4808-FOC/BSSE/F23 |


Project Report

See docs/Group7_DSA_Project_Report.pdf for full documentation.


 Future Improvements

 1. Time-complexity optimization for sorting large datasets.
 2. GUI for better user interaction
 3. Handle multiple doctors & departments
