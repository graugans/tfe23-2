# Informatik 3

Begleit Project für Informatik 3 bei TFE22-2 an der DHBW Ravensburg Campus Friedrichshafen

**WICHTIG** Bitte starten Sie Ihre IDE immer im Hauptverzeichnis dieses Projektes und nicht im Unterverzeichnis der entsprechenden Übungsaufgabe! Ansonsten werden können die Bibliotheken aus dem [contrib](contrib/) Verzeichnis nicht aufgelöst werden.

## Prepared Environments

[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/graugans/tfe22-2?quickstart=1)

## Synchronisation des eignen Forks

Es wird davon ausgegangen, dass Sie einen Fork angelegt haben und von diesen geklont haben. Damit entspricht Ihr Fork der Bezeichnung ``origin``. Siehe hierzu auch die [Hinweise in der ersten Übungsaufgabe](exercise-001#upstream-hinzuf%C3%BCgen).

Um die aktuellen Änderungen in die lokale Kopie des ``tfe22-2`` Repository zu übertragen sollten Sie zunächst ein ``git fetch`` durchführen

```sh
git fetch upstream
```

Nun checken wir die lokale Kopie des zu synchronisierenden Branches aus, in unserem Fall der ``main`` Branch. Dieser Schritt kann entfallen falls wir bereits schon auf dem ``main`` Branch sind. Das können Sie mit ``git branch -a`` prüfen.

```sh
git checkout main
```

Der Befehl ``git pull`` aktualisiert nun den lokalen Branch.

```sh
git pull upstream main
```

Sollte es hierbei zu einem Konflikt kommen haben Sie eventuell versehentlich lokale commits auf Ihrem ``main`` Branch durchgeführt. Das sollten Sie tunlichst vermeiden.

Im Erfolgsfall müssen jetzt nur noch die Daten in Ihren Fork gepusht werden:

```sh
git push origin main
```

## Übungsaufgaben

- [Übungsaufgabe Nr. 1](exercise-001/README.md)

## Hilfreiche Links

- [Markdown Cheat Sheet](https://guides.github.com/pdfs/markdown-cheatsheet-online.pdf)
- [Git Cheat Sheet](https://about.gitlab.com/images/press/git-cheat-sheet.pdf)
