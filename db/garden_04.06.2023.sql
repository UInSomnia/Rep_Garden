CREATE TABLE Role
(
	id integer PRIMARY KEY AUTOINCREMENT,
	name text,
	permission integer
);

CREATE TABLE Plot
(
	id integer PRIMARY KEY AUTOINCREMENT,
	number text
);

CREATE TABLE User
(
	id integer PRIMARY KEY AUTOINCREMENT,
	id_role integer,
	name text,
	surname text,
	patronymic text,
	phone text,
	mail text,
	password text,
	is_banned integer,
	FOREIGN KEY (id_role) REFERENCES Role(id)
);

CREATE TABLE User_to_Plot
(
	id integer PRIMARY KEY AUTOINCREMENT,
	id_user integer,
	id_plot integer,
	start_date datetime,
	finish_date datetime,
	FOREIGN KEY (id_user) REFERENCES User(id),
	FOREIGN KEY (id_plot) REFERENCES Plot(id)
);

CREATE TABLE Counter
(
	id integer PRIMARY KEY AUTOINCREMENT,
	id_plot integer,
	name text,
	FOREIGN KEY (id_plot) REFERENCES Plot(id)
);

CREATE TABLE Indicator
(
	id integer PRIMARY KEY AUTOINCREMENT,
	id_counter integer,
	year integer,
	month integer,
	day integer,
	hour integer,
	minute integer,
	second integer,
	T1 integer,
	T2 integer,
	FOREIGN KEY (id_counter) REFERENCES Counter(id)
);

