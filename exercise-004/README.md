# Aufgabenstellung


## Notwendige git Kommandos

```sh
git fetch --all
git switch -c solution-004 upstream/main
git status
git branch -a
git commit -m "fix: typo in Readme"
....
```

## Kapazitäten

Prüfen Sie die Vorlage und ändern sie diese so ab, dass nicht immer neuer Speicher reserviert wird und die Daten umkopiert werden, sondern zusätzlicher Speicher alloziert wird und anschließend bis zu Kapazitätsgrenze eingefügt wird und danach neuer Speicher alloziert wird.


## ## Strava für Vektoren

Damit Sie sich mit Ihren Kollegen messen können, interessiert Sie nur eine Sache. Geschwindigkeit. Wie schnell können Elemente in den Vector eingefügt werden. Dazu nutzen Sie die Funktionen der Bibliothek ``std::chrono``. Erstellen Sie einen Vorher Nachher Vergleich.

```cpp
auto start = std::chrono::system_clock::now();

/* do some work */

auto end = std::chrono::system_clock::now();
auto elapsed = end - start;
```

Vermutlich wird Ihr Rechner diese Aufgabe durchaus unter einer Sekunde lösen. Das heißt, Sie müssen ihn entweder mehr fordern oder eine andere Zeitbasis wählen.

```cpp
// this constructs a duration object using milliseconds
auto elapsed =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
```

Sie haben es erfasst, die Ergebnisse sind wieder mit ``{fmt}`` auszugeben.

Erstellen Sie anschließend einen Commit und pushen diesen in Ihr ``origin``

## Nach getaner Arbeit

Haben Sie alle Punkte erfolgreich abgearbeitet, erstellen Sie einen Merge-Request in Ihrem Fork und fügen mich ``graugans`` als Approval hinzu.

## Lernziele

- Vertiefung der git Kenntnisse
- Umgang mit Vektoren
- Zeitmessung mit ``std::chrono``
- Umgang mit dynamischem Speicher
