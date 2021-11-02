


//Character is a class that all character-related classes inherit.
//A character represents an active entity in a room, such as the player, 
//enemies or allied characters. Holds information such as the type of
//the character (player, enemy, allied) and its health points.

enum CharacterType {
    Player,
    Allied,
    Enemy
};

class Character {
    public:
    Character(CharacterType charactertype, int healthpoints); //Constructs a new character.

    ~Character(); //Destructor that destroys the character if health points
    //are reduced to zero or below.

    CharacterType GetCharacterType() const; //Returns the character type.

    int GetHealthPoints() const; //Returns the healthpoints of the character.

    void TakeDamage(int damage); //Reduces healthpoints by the amount of damage minus defense points.

    virtual void TakeAction() = 0; //Overridden by Allied and Enemy subclasses.
    //Causes Allies and Enemies to take an action.

    virtual const char PathFind() = 0; //Overridden by Allied and Enemy subclasses.
    //Returns the direction the character wants to move next as a character of "NEWS".

    protected:
    CharacterType charactertype_; //The type of the character.
    int healthpoints_; //The health points of the character.
    int defensepoints_; //The defense points of the character from using a shield. Blocks damage.
};