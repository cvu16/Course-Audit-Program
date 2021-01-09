# Project - CS 203 - Course Audit Program

## Intro
The purpose of this project is to create a program that will read students, degrees, departments from text files and then allow user to query for those items. The user can also use the command line to add, delete or edit the relationship of these items.

## Commands
•	c COURSE ### (e.g. c CS 205): shows course title and pre-requisites
•	d Degree Name (e.g. d AB Computer Science): shows course requirements for the degree
•	s COURSE ### (e.g. s ENG 205): shows courses to take next and degrees corresponding to the course
•	p type Name (e.g. p c ECON 101 OR p d Mathematics OR p g AB English): shows information associated with name. The type can be c - course, d - department, or g – degree
 a: takes fourparameters (department name, course name, course title, pre-requisites)
add a course (name, title, pre-requisites) to the department
  a Computer Science, CS 206, Systems Software, CS 202, CS 203
  
 m: takes one parameter (student name)
shows the courses student still has to take to satisfy the degree requirements
  m Lavonda Tyson
  >
  CS 406
  CS 470
  OR CS 320, CS 420
  OR MATH 186, MATH 286, MATH 336
  
 n: takes one parameter (student name)
shows the courses that the student can take next to satisfy the degree requirements (i.e.,
courses where the pre-requisites have been satisfied)
  n Tyree Miller
  >
  CS 202
  CS 203
  CS 205
  MATH 186
  
 r: takes two parameters (department, course name)
removes a course from a department; also removes the course from degree requirements and
as a pre-requisite for other courses.
  r Computer Science, CS 420

 p: the type parameter has an additional possible value: s - student
  p s Tyree Miller
  >
  degree: Computer Science
  completed: CS 104, CS 150
  
 q: takes two parameters (degree name, course name)
removes the course from the requirements; if it is one of two courses in a disjunct (OR)
convert the disjunct into an implicit conjunct (remove the OR)
  q BS Computer Science, CS 470

## Results
![Creation and Insertion Time](project31.PNG?raw=true "Creation Time")
![Print Time](project32.PNG?raw=true "Print Time")

As hypothesized, an index of words from a text file is most efficiently created by using HashMap. However, when it comes to returning in alphabetical order, TreeMap is more efficient than HashMap, and ListMap might be more efficient than TreeMap. However, the running time is also affected by the number of non-dictionary words in the text.
