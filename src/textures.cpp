#include <SFML/Graphics.hpp>

class Textures {
public:
	Textures() {
		//sf::Texture game_texture;
    	//game_texture.loadFromFile("../src/Graphics/GUI_Sprites/UI_PIC.png");
		//game_view = game_texture;

		game_view.loadFromFile("../src/Graphics/GUI_Sprites/UI_PIC.png");

		sf::Texture door_closed_t;
		door_closed_t.loadFromFile("../src/Graphics/TileSprites/DoorClosed.png");
		door_closed = door_closed_t;

		sf::Texture floor_t;
		floor_t.loadFromFile("../src/Graphics/TileSprites/Floor.png");
		floor = floor_t;

		sf::Texture levelexitclosed_t;
		levelexitclosed_t.loadFromFile("../src/Graphics/TileSprites/LevelExitClosed.png");
		levelexitclosed = levelexitclosed_t;

		sf::Texture levelexitopen_t;
		levelexitopen_t.loadFromFile("../src/Graphics/TileSprites/LevelExitOpen.png");
		levelexitopen = levelexitopen_t;

		sf::Texture pit_t;
		pit_t.loadFromFile("../src/Graphics/TileSprites/Pit.png");
		pit = pit_t;

		sf::Texture trap1_t;
		trap1_t.loadFromFile("../src/Graphics/TileSprites/Trap1.png");
		trap1 = trap1_t;

		sf::Texture trap2_t;
		trap2_t.loadFromFile("../src/Graphics/TileSprites/Trap2.png");
		trap2 = trap2_t;

		sf::Texture trap3_t;
		trap3_t.loadFromFile("../src/Graphics/TileSprites/Trap3.png");
		trap3 = trap3_t;

		sf::Texture wall_t;
		wall_t.loadFromFile("../src/Graphics/TileSprites/Wall.png");
		wall = wall_t;

		sf::Texture healthpotion_t;
		healthpotion_t.loadFromFile("../src/Graphics/ItemSprites/HealthPotion.png");
		healthpotion = healthpotion_t;

		sf::Texture staminapotion_t;
		staminapotion_t.loadFromFile("../src/Graphics/ItemSprites/StaminaPotion.png");
		staminapotion = staminapotion_t;

		sf::Texture shortsword_t;
		shortsword_t.loadFromFile("../src/Graphics/ItemSprites/ShortSword.png");
		shortsword = shortsword_t;

		sf::Texture armingsword_t;
		armingsword_t.loadFromFile("../src/Graphics/ItemSprites/ArmingSword.png");
		armingsword = armingsword_t;

		sf::Texture longsword_t;
		longsword_t.loadFromFile("../src/Graphics/ItemSprites/LongSword.png");
		longsword = longsword_t;

		sf::Texture hatchet_t;
		hatchet_t.loadFromFile("../src/Graphics/ItemSprites/Hatchet.png");
		hatchet = hatchet_t;

		sf::Texture battleaxe_t;
		battleaxe_t.loadFromFile("../src/Graphics/ItemSprites/BattleAxe.png");
		battleaxe = battleaxe_t;

		sf::Texture mace_t;
		mace_t.loadFromFile("../src/Graphics/ItemSprites/Mace.png");
		mace = mace_t;

		sf::Texture warhammer_t;
		warhammer_t.loadFromFile("../src/Graphics/ItemSprites/WarHammer.png");
		warhammer = warhammer_t;

		sf::Texture roundshield_t;
		roundshield_t.loadFromFile("../src/Graphics/ItemSprites/RoundShield.png");
		roundshield = roundshield_t;

		sf::Texture heatershield_t;
		heatershield_t.loadFromFile("../src/Graphics/ItemSprites/HeaterShield.png");
		heatershield = heatershield_t;

		sf::Texture kiteshield_t;
		kiteshield_t.loadFromFile("../src/Graphics/ItemSprites/KiteShield.png");
		kiteshield = kiteshield_t;

		sf::Texture towershield_t;
		towershield_t.loadFromFile("../src/Graphics/ItemSprites/TowerShield.png");
		towershield = towershield_t;

		sf::Texture sling_t;
		sling_t.loadFromFile("../src/Graphics/ItemSprites/Sling.png");
		sling = sling_t;

		sf::Texture bolas_t;
		bolas_t.loadFromFile("../src/Graphics/ItemSprites/Bolas.png");
		bolas = bolas_t;

		sf::Texture javelin_t;
		javelin_t.loadFromFile("../src/Graphics/ItemSprites/Javelin.png");
		javelin = javelin_t;

		sf::Texture aiaggressive_t;
		aiaggressive_t.loadFromFile("../src/Graphics/CharacterSprites/AI_Aggressive.png");
		aiaggressive = aiaggressive_t;

		sf::Texture aicareful_t;
		aicareful_t.loadFromFile("../src/Graphics/CharacterSprites/AI_Careful.png");
		aicareful = aicareful_t;

		sf::Texture aiboss_t;
		aiboss_t.loadFromFile("../src/Graphics/CharacterSprites/AI_Boss.png");
		aiboss = aiboss_t;

		sf::Texture airandom_t;
		airandom_t.loadFromFile("../src/Graphics/CharacterSprites/AI_Random.png");
		airandom = airandom_t;

		sf::Texture aistunned_t;
		aistunned_t.loadFromFile("../src/Graphics/CharacterSprites/AI_Stunned.png");
		aistunned = aistunned_t;

		sf::Texture defense1_t;
		defense1_t.loadFromFile("../src/Graphics/CharacterSprites/Defense1.png");
		defense1 = defense1_t;

		sf::Texture defense2_t;
		defense2_t.loadFromFile("../src/Graphics/CharacterSprites/Defense2.png");
		defense2 = defense2_t;

		sf::Texture defense3_t;
		defense3_t.loadFromFile("../src/Graphics/CharacterSprites/Defense3.png");
		defense3 = defense3_t;

		sf::Texture melee1_t;
		melee1_t.loadFromFile("../src/Graphics/CharacterSprites/Melee1.png");
		melee1 = melee1_t;

		sf::Texture melee2_t;
		melee2_t.loadFromFile("../src/Graphics/CharacterSprites/Melee2.png");
		melee2 = melee2_t;

		sf::Texture melee3_t;
		melee3_t.loadFromFile("../src/Graphics/CharacterSprites/Melee3.png");
		melee3 = melee3_t;

		sf::Texture ranged1_t;
		ranged1_t.loadFromFile("../src/Graphics/CharacterSprites/Ranged1.png");
		ranged1 = ranged1_t;

		sf::Texture ranged2_t;
		ranged2_t.loadFromFile("../src/Graphics/CharacterSprites/Ranged2.png");
		ranged2 = ranged2_t;

		sf::Texture ranged3_t;
		ranged3_t.loadFromFile("../src/Graphics/CharacterSprites/Ranged3.png");
		ranged3 = ranged3_t;

		sf::Texture emptyaction_t;
		emptyaction_t.loadFromFile("../src/Graphics/CharacterSprites/Empty.png");
		emptyaction = emptyaction_t;

		sf::Texture enemybase_t;
		enemybase_t.loadFromFile("../src/Graphics/CharacterSprites/Enemy.png");
		enemybase = enemybase_t;

		sf::Texture playerbase_t;
		playerbase_t.loadFromFile("../src/Graphics/CharacterSprites/Player.png");
		playerbase = playerbase_t;

		sf::Texture depth1_t;
		depth1_t.loadFromFile("../src/Graphics/GUI_Sprites/Depth1.png");
		depth1 = depth1_t;

		sf::Texture depth2_t;
		depth2_t.loadFromFile("../src/Graphics/GUI_Sprites/Depth2.png");
		depth2 = depth2_t;

		sf::Texture depth3_t;
		depth3_t.loadFromFile("../src/Graphics/GUI_Sprites/Depth3.png");
		depth3 = depth3_t;

		sf::Texture depth4_t;
		depth4_t.loadFromFile("../src/Graphics/GUI_Sprites/Depth4.png");
		depth4 = depth4_t;

		sf::Texture depth5_t;
		depth5_t.loadFromFile("../src/Graphics/GUI_Sprites/Depth5.png");
		depth5 = depth5_t;

		sf::Texture depth6_t;
		depth6_t.loadFromFile("../src/Graphics/GUI_Sprites/Depth6.png");
		depth6 = depth6_t;

		sf::Texture health0_t;
		health0_t.loadFromFile("../src/Graphics/GUI_Sprites/Health0.png");
		health0 = health0_t;

		sf::Texture health1_t;
		health1_t.loadFromFile("../src/Graphics/GUI_Sprites/Health1.png");
		health1 = health1_t;

		sf::Texture health2_t;
		health2_t.loadFromFile("../src/Graphics/GUI_Sprites/Health2.png");
		health2 = health2_t;

		sf::Texture health3_t;
		health3_t.loadFromFile("../src/Graphics/GUI_Sprites/Health3.png");
		health3 = health3_t;
		
		sf::Texture health4_t;
		health4_t.loadFromFile("../src/Graphics/GUI_Sprites/Health4.png");
		health4 = health4_t;

		sf::Texture nrzero_t;
		nrzero_t.loadFromFile("../src/Graphics/GUI_Sprites/0.png");
		nrzero = nrzero_t;

		sf::Texture nrone_t;
		nrone_t.loadFromFile("../src/Graphics/GUI_Sprites/1.png");
		nrone = nrone_t;

		sf::Texture nrtwo_t;
		nrtwo_t.loadFromFile("../src/Graphics/GUI_Sprites/2.png");
		nrtwo = nrtwo_t;

		sf::Texture nrthree_t;
		nrthree_t.loadFromFile("../src/Graphics/GUI_Sprites/3.png");
		nrthree = nrthree_t;

		sf::Texture nrfour_t;
		nrfour_t.loadFromFile("../src/Graphics/GUI_Sprites/4.png");
		nrfour = nrfour_t;

		sf::Texture nrfive_t;
		nrfive_t.loadFromFile("../src/Graphics/GUI_Sprites/5.png");
		nrfive = nrfive_t;

		sf::Texture nrsix_t;
		nrsix_t.loadFromFile("../src/Graphics/GUI_Sprites/6.png");
		nrsix = nrsix_t;

		sf::Texture nrseven_t;
		nrseven_t.loadFromFile("../src/Graphics/GUI_Sprites/7.png");
		nrseven = nrseven_t;

		sf::Texture nreight_t;
		nreight_t.loadFromFile("../src/Graphics/GUI_Sprites/8.png");
		nreight = nreight_t;

		sf::Texture nrinf_t;
		nrinf_t.loadFromFile("../src/Graphics/GUI_Sprites/Inf.png");
		nrinf = nrinf_t;

		sf::Texture att_t;
		att_t.loadFromFile("../src/Graphics/GUI_Sprites/Att.png");
		att = att_t;

		sf::Texture defse_t;
		defse_t.loadFromFile("../src/Graphics/GUI_Sprites/Def.png");
		defse = defse_t;

		sf::Texture coold_t;
		coold_t.loadFromFile("../src/Graphics/GUI_Sprites/CD.png");
		coold = coold_t;

		sf::Texture maxcoold_t;
		maxcoold_t.loadFromFile("../src/Graphics/GUI_Sprites/TCD.png");
		maxcoold = maxcoold_t;

		sf::Texture dur_t;
		dur_t.loadFromFile("../src/Graphics/GUI_Sprites/Dur.png");
		dur = dur_t;

		sf::Texture nonum_t;
		nonum_t.loadFromFile("../src/Graphics/GUI_Sprites/NoNum.png");
		nonum = nonum_t;

		sf::Texture infobtnview_t;
		infobtnview_t.loadFromFile("../src/Graphics/GUI_Sprites/infobtnview.png");
		infobtnview = infobtnview_t;

		sf::Texture diminvbutton_t;
		diminvbutton_t.loadFromFile("../src/Graphics/GUI_Sprites/DimInvButton.png");
		diminvbutton = diminvbutton_t;

		sf::Texture hugeslimeinfo_t;
		hugeslimeinfo_t.loadFromFile("../src/Graphics/CharacterInfoSprites/HugeSlimeInfo.png");
		hugespiderinfo = hugeslimeinfo_t;

		sf::Texture hugespiderinfo_t;
		hugespiderinfo_t.loadFromFile("../src/Graphics/CharacterInfoSprites/HugeSpiderInfo.png");
		hugespiderinfo = hugespiderinfo_t;

		sf::Texture largeslimeinfo_t;
		largeslimeinfo_t.loadFromFile("../src/Graphics/CharacterInfoSprites/LargeSlimeInfo.png");
		largeslimeinfo = largeslimeinfo_t;

		sf::Texture lichinfo_t;
		lichinfo_t.loadFromFile("../src/Graphics/CharacterInfoSprites/LichInfo.png");
		lichinfo = lichinfo_t;

		sf::Texture selectionrectangle_t;
		selectionrectangle_t.loadFromFile("../src/Graphics/CharacterInfoSprites/SelectionRectangle.png");
		selectionrectangle = selectionrectangle_t;

		sf::Texture skeletonarcherinfo_t;
		skeletonarcherinfo_t.loadFromFile("../src/Graphics/CharacterInfoSprites/SkeletonArcherInfo.png");
		skeletonarcherinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SkeletonArcherInfo.png");

		skeletoninfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SkeletonInfo.png");
		skeletonknightinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SkeletonKnightInfo.png");
		skeletonmageinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SkeletonMageInfo.png");
		skeletonwarriorinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SkeletonWarriorInfo.png");
		slimeinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SlimeInfo.png");
		spiderinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SpiderInfo.png");
		spitterinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SpitterInfo.png");
		armingswordinfo.loadFromFile("../src/Graphics/ItemInfoSprites/ArmingSwordInfo.png");
		battleaxeinfo.loadFromFile("../src/Graphics/ItemInfoSprites/BattleAxeInfo.png");
		bolasinfo.loadFromFile("../src/Graphics/ItemInfoSprites/BolasInfo.png");
		hatchetinfo.loadFromFile("../src/Graphics/ItemInfoSprites/HatchetInfo.png");
		healingpotioninfo.loadFromFile("../src/Graphics/ItemInfoSprites/HealingPotionInfo.png");
		heatershieldinfo.loadFromFile("../src/Graphics/ItemInfoSprites/HeaterShieldInfo.png");
		javelininfo.loadFromFile("../src/Graphics/ItemInfoSprites/JavelinInfo.png");
		kiteshieldinfo.loadFromFile("../src/Graphics/ItemInfoSprites/KiteShieldInfo.png");
		longswordinfo.loadFromFile("../src/Graphics/ItemInfoSprites/LongSwordInfo.png");
		maceinfo.loadFromFile("../src/Graphics/ItemInfoSprites/MaceInfo.png");
		roundshieldinfo.loadFromFile("../src/Graphics/ItemInfoSprites/RoundShieldInfo.png");
		shortswordinfo.loadFromFile("../src/Graphics/ItemInfoSprites/ShortSwordInfo.png");
		slinginfo.loadFromFile("../src/Graphics/ItemInfoSprites/SlingInfo.png");
		staminapotioninfo.loadFromFile("../src/Graphics/ItemInfoSprites/StaminaPotionInfo.png");
		towershieldinfo.loadFromFile("../src/Graphics/ItemInfoSprites/TowerShieldInfo.png");
		warhammerinfo.loadFromFile("../src/Graphics/ItemInfoSprites/WarHammerInfo.png");
	}

	sf::Texture game_view;
	sf::Texture door_closed;
	sf::Texture floor;
	sf::Texture levelexitclosed;
	sf::Texture levelexitopen;
	sf::Texture pit;
	sf::Texture trap1;
	sf::Texture trap2;
	sf::Texture trap3;
	sf::Texture wall;
	sf::Texture healthpotion;
	sf::Texture staminapotion;
	sf::Texture shortsword;
	sf::Texture armingsword;
	sf::Texture longsword;
	sf::Texture hatchet;
	sf::Texture battleaxe;
	sf::Texture mace;
	sf::Texture warhammer;
	sf::Texture roundshield;
	sf::Texture heatershield;
	sf::Texture kiteshield;
	sf::Texture towershield;
	sf::Texture sling;
	sf::Texture bolas;
	sf::Texture javelin;
	sf::Texture aiaggressive;
	sf::Texture aicareful;
	sf::Texture aiboss;
	sf::Texture airandom;
	sf::Texture aistunned;
	sf::Texture defense1;
	sf::Texture defense2;
	sf::Texture defense3;
	sf::Texture melee1;
	sf::Texture melee2;
	sf::Texture melee3;
	sf::Texture ranged1;
	sf::Texture ranged2;
	sf::Texture ranged3;
	sf::Texture emptyaction;
	sf::Texture enemybase;
	sf::Texture playerbase;
	sf::Texture depth1;
	sf::Texture depth2;
	sf::Texture depth3;
	sf::Texture depth4;
	sf::Texture depth5;
	sf::Texture depth6;
	sf::Texture health0;
	sf::Texture health1;
	sf::Texture health2;
	sf::Texture health3;
	sf::Texture health4;
	sf::Texture nrzero;
	sf::Texture nrone;
	sf::Texture nrtwo;
	sf::Texture nrthree;
	sf::Texture nrfour;
	sf::Texture nrfive;
	sf::Texture nrsix;
	sf::Texture nrseven;
	sf::Texture nreight;
	sf::Texture nrinf;
	sf::Texture att;
	sf::Texture defse;
	sf::Texture coold;
	sf::Texture maxcoold;
	sf::Texture dur;
	sf::Texture nonum;
	sf::Texture infobtnview;
	sf::Texture diminvbutton;
	sf::Texture hugeslimeinfo;
	sf::Texture hugespiderinfo;
	sf::Texture largeslimeinfo;
	sf::Texture lichinfo;
	sf::Texture selectionrectangle;
	sf::Texture skeletonarcherinfo;
	sf::Texture skeletoninfo;
	sf::Texture skeletonknightinfo;
	sf::Texture skeletonmageinfo;
	sf::Texture skeletonwarriorinfo;
	sf::Texture slimeinfo;
	sf::Texture spiderinfo;
	sf::Texture spitterinfo;
	sf::Texture armingswordinfo;
	sf::Texture battleaxeinfo;
	sf::Texture bolasinfo;
	sf::Texture hatchetinfo;
	sf::Texture healingpotioninfo;
	sf::Texture heatershieldinfo;
	sf::Texture javelininfo;
	sf::Texture kiteshieldinfo;
	sf::Texture longswordinfo;
	sf::Texture maceinfo;
	sf::Texture roundshieldinfo;
	sf::Texture shortswordinfo;
	sf::Texture slinginfo;
	sf::Texture staminapotioninfo;
	sf::Texture towershieldinfo;
	sf::Texture warhammerinfo;
};