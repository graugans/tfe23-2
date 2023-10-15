# Aufgabenstellung

## Parameterraum

Ändern Sie die Vorlage so ab, dass Sie einen Parameter ``count`` mittels Kommandozeile ``-c,--count`` übergeben können. Falls kein Parameter angegeben wird, so ist der Standardwert mit 20 festzusetzen.

Erstellen Sie anschließend einen Commit und pushen diesen.

## Den Zufall einordnen

Erstellen Sie einen ``std::vector`` mit der Größe von ``count`` und füllen diesen mit zufälligen Werten von 1-100.

Erstellen Sie anschließend einen Commit und pushen diesen.

## Zeig es mir Baby

Damit Sie den Zufall kenne, müssen Sie ihn ausgeben können. Verwenden Sie hierzu die ``{fmt}`` Bibliothek und erstellen Sie eine Funktion, um den Vektor auszugeben.

Erstellen Sie anschließend einen Commit und pushen diesen.

## Der Zufall in geordneten Bahnen

Sortieren Sie nun den Vector der Reihe nach. Das heißt die niedrigste Zahl zuerst. Das Ergebnis soll ebenfalls ausgegeben werden.

Erstellen Sie anschließend einen Commit und pushen diesen.

## Strava für Vektoren

Damit Sie sich mit Ihren Kollegen messen können, interessiert Sie nur eine Sache. Geschwindigkeit. Wie schnell wurde der Vektor sortiert. Dazu nutzen Sie die Funktionen der Bibliothek ``std::chrono``

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
- Erste Schritte mit CMake
- Umgang mit Vektoren
- Umgang mit der CLI11
- Umgang mit der ``{fmt}`` Bibliothek
- Anwenden der [Algorithms library](https://en.cppreference.com/w/cpp/algorithm)
- Zeitmessung mit ``std::chrono``

## Anmerkungen

- Verwenden Sie, falls möglich range based for loops siehe auch [es71](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es71-prefer-a-range-for-statement-to-a-for-statement-when-there-is-a-choice) aus den Cpp Core Guidelines
- Achten Sie darauf, bei Parametern möglichst immer das Schlüsselwort ``const`` zu verwenden.
