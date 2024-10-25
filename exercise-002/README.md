# Aufgabenstellung

## Notwendige git Kommandos

```sh
git status
git branch -a
git fetch --all
# create a new local branch based on the upstream (graugans)
git switch -c solution-002 upstream/main
# copy the folder exercise-001 to exercise-002
cp exercise-001/ exercise-002 -r
# modify the CMakeLists.txt and main.cpp in the directory exercise-002
# modify the top-level CMakeLists.txt
# commit the changes
git add exercise-002
git commit -m "feat: add exercise number two"
# push the changes to the cloud
git push -u origin solution-002
....
```

## Wiederholung Speicherbereiche in C/C++

Wir erstellen globale und lokale Variablen.

## Lernziele

- Vertiefung der git Kenntnisse
- Erste Schritte mit CMake
- Umgang mit Speicherbereichen

## Anmerkungen

- Verwenden Sie, falls möglich range based for loops siehe auch [es71](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es71-prefer-a-range-for-statement-to-a-for-statement-when-there-is-a-choice) aus den Cpp Core Guidelines
- Achten Sie darauf, bei Parametern möglichst immer das Schlüsselwort ``const`` zu verwenden.
