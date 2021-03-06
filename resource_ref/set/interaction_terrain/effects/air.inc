;SDL
{"air"
	{on detonate

		{if stuff "grenade fire"							; Molotov Grenades
			{spawn "ex_glass_ic_air"}
			;{spawn "burn_piece" dir_velocity}

		else stuff "grenade size1"							; Anti-Personnel Grenades
			{start_sound "detonation/grenade/bkg/" use_position}
			{spawn "ex_air_norm"}

		else stuff "grenade size2"							; Anti-Tank Grenades
			{start_sound "detonation/he_size1/bkg/" use_position}
			{spawn "ex_air_big"}

		else stuff "grenade size3"							; Dynamite/Satchel Charges
			{start_sound "detonation/he_size2/bkg/" use_position}
			{spawn "ex_grenade_size3"}

		else stuff "mortar"
			{start_sound "detonation/he_size2/bkg/" use_position}
			;{spawn "metal_hit_br"}

		else stuff "big mortar"
			{start_sound "detonation/he_size3/bkg/" use_position}
			;{spawn "metal_hit_br"}

		else stuff "shell size3 he"
			{start_sound "detonation/he_size3/bkg/" use_position}
			{spawn "metal_hit_fg_big"}

		else stuff "shell size4 he"
			{start_sound "detonation/he_size3/bkg/" use_position}
			{spawn "metal_hit_fg_big"}	;should use bigger, but that fx is missing update?

		else stuff "shell smoke wp_small"							; small WP Smoke shells
			{spawn "ex_wp_small"}									; initial explosion fx
			{spawn "shell_smoke_wp_small"}							; actual smoke and vision volumes

		else stuff "shell smoke wp_medium"							; medium WP Smoke shells
			{spawn "ex_wp_medium"}									; initial explosion fx
			{spawn "shell_smoke_wp_medium"}							; actual smoke and vision volumes

		else stuff "shell smoke wp_big"								; big WP Smoke shells
			{spawn "ex_wp_big"}										; initial explosion fx
			{spawn "shell_smoke_wp_big"}							; actual smoke and vision volumes

		else stuff "shell smoke"							; All cannon Smoke shells
			{spawn "mortar_smoke"}									; initial explosion fx
			{spawn "shell_smoke"}									; actual smoke and vision volumes

		else stuff "bomb size1"								; 50-60kg bombs / explosives
			{start_sound "detonation/50kg_bomb/bkg/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_50kg"}

		else stuff "bomb size2"								; 100-200kg bombs / explosives
			{start_sound "detonation/100kg_bomb/bkg/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_100kg"}

		else stuff "bomb size3"								; 250kg+ bomb
			{start_sound "detonation/250kg_bomb/bkg/" use_position}
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_250kg"}

		else stuff "mine antipersonnel"						; Anti-Personnel Mines
			{start_sound "detonation/he_size1/bkg/" use_position}
			{spawn "ex_air_norm"}
			{spawn "grenade_shellhole" terrain_texmod}

		else stuff "glass ic"								; Ampulomet glass ball
			{spawn "ex_glass_ic_air"}
			{spawn "burn_piece" dir_velocity}
		}
	}
}
