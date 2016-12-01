# F_TREE
Generates a basic family tree based on the input

# Usage
```bash
# Clone
git clone git@github.com:langee99/F_Tree.git

# Compile
make

# Usage
./ftree < test/test1
```

# Input
#### File layout *(PERSON is the only thing needed to be declared)*
```
PERSON        <name> // Needs to be declared before any of the following
  FATHER      <name>
  FATHER_OF   <name>
  MOTHER      <name>
  MOTHER_OF   <name>
  SEX         <M|F>

PERSON
  FATHER
  .
  .
  .

.
.
.

```
#### ***Examples are in /test*
