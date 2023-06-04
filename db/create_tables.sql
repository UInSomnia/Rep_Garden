CREATE TABLE Role
(
    id INTEGER PRIMARY KEY NOT NULL,
    name TEXT,
    permission INTEGER
);

CREATE TABLE User
(
    id INTEGER PRIMARY KEY NOT NULL,
    id_role INTEGER NOT NULL,
    name TEXT,
    surname TEXT,
    patronymic TEXT,
    phone TEXT,
    mail TEXT,
    password TEXT,
    address TEXT,
    is_banned INTEGER,
    FOREIGN KEY (id_role) REFERENCES Role(id)
);

CREATE TABLE Indication
(
    id INTEGER PRIMARY KEY NOT NULL,
    id_counter INTEGER NOT NULL,
    month INTEGER,
    year INTEGER,
    T1 INTEGER,
    T2 INTEGER,
    FOREIGN KEY (id_counter) REFERENCES Counter(id)
);

CREATE TABLE Counter
(
    id INTEGER PRIMARY KEY NOT NULL,
    id_user INTEGER NOT NULL,
    name TEXT,
    FOREIGN KEY (id_user) REFERENCES User(id)
);

