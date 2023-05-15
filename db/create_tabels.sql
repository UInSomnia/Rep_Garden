CREATE TABLE User
(
    id INTEGER PRIMARY KEY NOT NULL,
    name TEXT,
    surname TEXT,
    patronymic TEXT,
    phone TEXT,
    mail TEXT,
    password TEXT
);

CREATE TABLE Indication
(
    id INTEGER PRIMARY KEY NOT NULL,
    id_user INTEGER NOT NULL,
    month INTEGER,
    year INTEGER,
    T1 INTEGER,
    T2 INTEGER
);
