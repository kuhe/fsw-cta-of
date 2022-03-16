;SDL
{"mud"
	{on hit
		{if min_mass 100
			{if effector "tree"
				{spawn "tree_crush"}
			else
				{spawn "spheredust_small"}
			}
		else min_mass 10
			{spawn "spheredust_tiny"}
		else effector "shell_cannon"
			{spawn "spheredust_shell"}
		}
	}
	{on detonate

		{if stuff "grenade fire"							; Molotov Grenades
			{spawn "ex_molot_ground"}

		else stuff "rifle_grenade_at"						; HEAT rifle Grenades
			{start_sound "detonation/grenade/bkg/" use_position}
			{spawn "ex_grenade_size1"}
			{spawn "grenade_shellhole" terrain_texmod}

		else stuff "grenade size1"							; Anti-Personnel Grenades
			{start_sound "detonation/grenade/bkg/" use_position}
			{spawn "ex_grenade_size1"}
			{spawn "grenade_shellhole" terrain_texmod}

		else stuff "grenade size2"							; Anti-Tank Grenades
			{start_sound "detonation/he_size1/bkg/" use_position}
			{spawn "ex_grenade_size2"}
			{spawn "grenade_at_shellhole" terrain_texmod}

		else stuff "grenade size3"							; Dynamite/Satchel Charges
			{start_sound "detonation/he_size2/bkg/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_grenade_size3"}
			{spawn "crater_small" terrain_texmod}

		else stuff "bullet_fx size1"						; Pistol/SMG Ammo
			{spawn "ex_bul_sm_mud"}

		else stuff "bullet_fx size2"						; Rifle/MG ammo
			{spawn "ex_bul_sm_mud"}

		else stuff "bullet_fx size3"						; AT Rifle/HMG ammo
			{spawn "ex_bul_sm_mud"}

		else stuff "mortar big ic"							; 120mm Mortar incendiary
			{start_sound "detonation/he_size1/bkg/" use_position}
			{start_sound "fire/bush/" use_position}
			{spawn "ex_ic_120_ground"}
			{spawn "burn_piece" dir_velocity}
			{spawn "burned_spot_round2" scale 1.4 random_orientation}
			{fire radius 4 time 20 heating 0.25}

		else stuff "mortar big"								; 120mm Mortar shells
			{start_sound "detonation/he_size3/bkg/" use_position}
			{spawn "ex_mort_big"}
			{spawn "crater_small" terrain_texmod}

		else stuff "mortar"									; 80mm Mortar shells
			{start_sound "detonation/he_size2/bkg/" use_position}
			{spawn "ex_mort_sm"}
			{spawn "crater_tiny" terrain_texmod}

		else stuff "shell size2 heat_shell"							; 75-104mm cannon HEAT shells
			{start_sound "detonation/he_size2/bkg/" use_position}
			{spawn "ex_he_size2_mud"}
			{spawn "crater_tiny" terrain_texmod}

		else stuff "shell size3 heat_shell"							; 105-149mm cannon HEAT shells
			{start_sound "detonation/he_size3/bkg/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size3_mud"}
			{spawn "crater_small" terrain_texmod}

		else stuff "heat_shell"									; All HEAT Shells / AT Rockets
			{start_sound "detonation/he_size1/bkg/" use_position}
			{spawn "shockwave"}
			{spawn "ex_heat"}
			{spawn "grenade_at_shellhole" terrain_texmod}

		else stuff "auto size1 he"							; 20-25mm Autocannon HE shells
			{start_sound "detonation/auto_shell/bkg/" use_position}
			{spawn "ex_he_autocannon_mud"}

		else stuff "auto size1 aphe"						; 20-25mm Autocannon APHE shells
			{start_sound "detonation/auto_shell/bkg/" use_position}
			{spawn "ex_he_autocannon_mud"}

		else stuff "auto size1"								; 20-25mm Autocannon AP shells
			{spawn "ex_ap_autocannon_mud"}

		else stuff "auto size2 he"							; 37-40mm Autocannon HE shells
			{start_sound "detonation/auto_shell/bkg/" use_position}
			{spawn "ex_he_autocannon_mud"}

		else stuff "auto size2"								; 37-40mm Autocannon AP shells
			{spawn "ex_ap_autocannon_mud"}

		else stuff "shell size1 he"							; 37-74mm cannon HE shells
			{start_sound "detonation/he_size1/bkg/" use_position}
			{spawn "ex_he_size1_mud"}
			{spawn "grenade_shellhole" terrain_texmod scale 0.75}

		else stuff "shell size1"							; 37-74mm cannon AP shells
			{start_sound "detonation/ap_shell/bkg/" use_position}
			{spawn "ex_ap_size1_mud"}
			{spawn "ap_shellhole"}

		else stuff "shell size2 he"							; 75-104mm cannon HE shells
			{start_sound "detonation/he_size2/bkg/" use_position}
			{spawn "ex_he_size2_mud"}
			{spawn "crater_tiny" terrain_texmod}

		else stuff "shell size2"							; 75-104mm cannon AP shells
			{start_sound "detonation/ap_shell/bkg/" use_position}
			{spawn "ex_ap_size2_mud"}
			{spawn "ap_shellhole"}

		else stuff "shell size3 he"							; 105-149mm cannon HE shells
			{start_sound "detonation/he_size3/bkg/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size3_mud"}
			{spawn "crater_small" terrain_texmod}

		else stuff "shell size3"							; 105-149mm cannon AP shells
			{start_sound "detonation/ap_shell/bkg/" use_position}
			{spawn "crater_tiny" terrain_texmod}
			{spawn "ex_ap_size3_mud"}
			{spawn "grenade_shellhole" terrain_texmod}

		else stuff "shell size4 he"							; 150-169mm cannon HE shells
			{start_sound "detonation/he_size4/bkg/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size4"}
			{spawn "crater_medium" terrain_texmod}

		else stuff "shell size4"							; 150-169mm cannon AP shells
			{start_sound "detonation/ap_shell/bkg/" use_position}
			{spawn "crater_tiny" terrain_texmod}
			{spawn "shockwave_sphere"}
			{spawn "ex_ap_size4_mud"}
			{spawn "crater_tiny" terrain_texmod}

		else stuff "shell size5"							; 170mm+ cannon HE shells
			{start_sound "detonation/he_size5/bkg/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size5"}
			{spawn "crater_massive" terrain_texmod}
			
		else stuff "shell size6"							; 240mm+ cannon HE shells
			{start_sound "detonation/he_size5/bkg/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size6"}
			{spawn "crater_massive" terrain_texmod}

		else stuff "shell smoke wp_small"							; small WP Smoke shells
			{spawn "ex_wp_small"}									; initial explosion fx
			{spawn "shell_smoke_wp_small"}							; actual smoke and vision volumes
			{spawn "ap_shellhole"}

		else stuff "shell smoke wp_medium"							; medium WP Smoke shells
			{spawn "ex_wp_medium"}									; initial explosion fx
			{spawn "shell_smoke_wp_medium"}							; actual smoke and vision volumes
			{spawn "ap_shellhole"}

		else stuff "shell smoke wp_big"								; big WP Smoke shells
			{spawn "ex_wp_big"}										; initial explosion fx
			{spawn "shell_smoke_wp_big"}							; actual smoke and vision volumes
			{spawn "ap_shellhole"}

		else stuff "shell smoke"							; All cannon Smoke shells
			{spawn "mortar_smoke"}									; initial explosion fx
			{spawn "shell_smoke"}									; actual smoke and vision volumes
			{spawn "ap_shellhole"}

		else stuff "bomb size1"								; 50-60kg bombs / explosives
			{start_sound "detonation/50kg_bomb/bkg/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_50kg"}
			{spawn "crater_medium" terrain_texmod}

		else stuff "bomb size2"								; 100-200kg bombs / explosives
			{start_sound "detonation/100kg_bomb/bkg/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_100kg"}
			{spawn "crater_big" terrain_texmod}

		else stuff "bomb size3"								; 250kg+ bomb
			{start_sound "detonation/250kg_bomb/bkg/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_250kg"}
			{spawn "crater_massive" terrain_texmod}

		else stuff "mine antipersonnel"						; Anti-Personnel Mines
			{start_sound "detonation/he_size1/bkg/" use_position}
			{spawn "ex_grenade_size1"}
			{spawn "grenade_shellhole" terrain_texmod}

		else stuff "mine antitank"							; Anti-Tank Mines
			{start_sound "detonation/he_size2/bkg/" use_position}
			{spawn "ex_at_mine"}
			{spawn "grenade_at_shellhole" terrain_texmod}

		else stuff "flare marker"							; Special Flare ammo for mission scripts
			{spawn "flare_marker"}
			{spawn "spheredust_small"}

		else stuff "flare artillery"						; Flare for off-map Artillery
			{spawn "flare_artillery"}
			{spawn "spheredust_small"}

		else stuff "glass ic"								; Ampulomet glass ball
			{spawn "ex_glass_ic_ground"}
			{spawn "burn_piece" dir_velocity}
			{spawn "burned_spot_round2" random_orientation}
			{fire radius 2 time 20 heating 0.25}
		}
	}
}