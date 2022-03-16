
; Presets for health and stamina levels

(include "/set/breed/presets/perks/skills.inc")


;/*=========== Unique Presets Begin ===========*/

(define "spetsnaz"			;// Soviet Spetsnaz
	{"stealth"}
	{"stamina" "400%"}
	{"telescope"}
	{"vision" human_elite}
	{"aimedshot"}			;// Silenced Nagant Pistol
)

(define "sniper_rus"		;// Soviet Snipers
	{"stamina" "300%"}
)

(define "paratrooper"		;// Soviet Paratroopers
	{"speed" 1.10}
	{"health" "300%"}
	{"stamina" "250%"}
)

(define "mountain_rifle"	;// Soviet Mountain rifles
	{"speed" 1.10}
	{"health" "250%"}
	{"stamina" "300%"}
)

(define "assault_sapper"	;// Soviet Assault Sappers
	{"speed" 0.80}
	{"health" "400%"}
)

(define "guards"			;// Soviet Guards infantry
	{"health" "300%"}
	{"stamina" "150%"}
	{"stamina_regeneration" "125%"}
)

(define "guards_marines"	;// Soviet Guards marine infantry
	{"health" "350%"}
	{"stamina" "220%"}
	{"stamina_regeneration" "175%"}
)

(define "blau"				;// Blau division
	{"speed" 0.80}
	{"health" "300%"}
)

(define "brandenburger"		;// German Brandenburgers
	{"stealth"}
	{"speed" 1.20}
	{"health" "300%"}
	{"stamina" "250%"}
)

(define "vet_reg"			;// Veteran regular units
	{"health" "250%"}
	{"stamina" "150%"}
	{"stamina_regeneration" "120%"}
)

(define "grossdeutschland"	;// German Grossdeutschland division inf/panzergrenadiers
	{"health" "300%"}
	{"stamina" "180%"}
	{"stamina_regeneration" "150%"}
)

(define "gebirgsjager"		;// German Gebirgsjäger
	{"health" "300%"}
	{"stamina" "350%"}
)

(define "fallschirmjager"	;// German Fallschirmjäger
	{"health" "350%"}
	{"stamina" "300%"}
)

(define "partisan"			;// Partisans
	{"speed" 0.90}
)

(define "volkssturm"
	{"pistol" lvl_1}
	{"smg" lvl_1}
	{"mgun" lvl_1}
	{"rifle" lvl_1}
	{"melee" lvl_1}
	{"avoidance" lvl_1}
	("at_rank_1")
	("health_rank_1")
	("fortification")
	("basic_repair")
)

(define "recon"				;// recon soldiers
	{"health" "150%"}
	{"stamina" "175%"}
	{"stamina_regeneration" "110%"}
	("recon_vision")
)

(define "tank_commander"	;// Tank Commander
	("loader_skill_smg_rank_2")
	("skilled_repair")
	{"health" "150%"}
	("expert_gun")
)

(define "tankman"			;// Tank Crew
	("loader_skill_smg_rank_2")
	("skilled_repair")
	{"health" "150%"}
	("skilled_gun")
)

;/*=========== Unique Presets End ===========*/