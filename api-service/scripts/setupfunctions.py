import sqlite3

def setup_platforms(path_to_db):
    platforms = [
        (1, 'PC'),
        (2, 'Nintendo GameCube'),
        (3, 'Nintendo 64'),
        (4, 'Nintendo Game Boy'),
        (5, 'Nintendo Game Boy Advance'),
        (6, 'Super Nintendo Entertainment System'),
        (7, 'Nintendo Entertainment System'),
        (8, 'Nintendo DS'),
        (9, 'Nintendo Wii'),
        (10, 'Sony PlayStation'),
        (11, 'Sony PlayStation 2'),
        (12, 'Sony PlayStation 3'),
        (13, 'Sony PLayStation Portable'),
        (14, 'Microsoft Xbox'),
        (15, 'Microsoft Xbox 360'),
        (16, 'Sega Dreamcast'),
        (17, 'Sega Saturn'),
        (18, 'Sega Genesis'),
        # (19, ''),
        (20, 'Sega Game Gear'),
        (21, 'Sega CD'),
        (22, 'Atari 2600'),
        (23, 'Arcade'),
        (24, 'Neo Geo'),
        (25, '3DO'),
        (26, 'Atari 5200'),
        (27, 'Atari 7800'),
        (28, 'Atari Jaguar'),
        (29, 'Atari Jaguar CD'),
        (30, 'Atari XE'),
        (31, 'Colecovision'),
        (32, 'Intellivision'),
        (33, 'Sega 32X'),
        (34, 'TurboGrafx 16'),
        (35, 'Sega Master System'),
        (36, 'Sega Mega Drive'),
        (37, 'Mac OS'),
        (38, 'Nintendo Wii U'),
        (39, 'Sony PlayStation Vite'),
        (40, 'Commodore 64'),
        (41, 'Nintendo Game Boy Color')
    ]

    base = sqlite3.connect(path_to_db)
    cursor = base.cursor()
    cursor.execute('CREATE TABLE IF NOT EXISTS platforms (id INTEGER PRIMARY KEY, name TEXT, default_emulator_id INTEGER)')
    cursor.execute('DELETE FROM platforms')
    cursor.executemany('INSERT INTO platforms VALUES (?,?, NULL)', platforms)
    base.commit()
    base.close()

setup_platforms('D:/Source/retrofox/sln/core/testbase.db')