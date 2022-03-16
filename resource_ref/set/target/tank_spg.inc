{selector
	{type "tank_spg"}
	{group
		{ignore {class airborne}}
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_small}}
		{sort {class cannon_zenite}}
		{sort distance}
	}
	{group
		{sort {class tank_heavy}}
		{sort {class tank_medium}}
		{sort {class tank_light}}
		{sort {class car_cannon}}
		{sort {class tank_bullet}}
		{sort {attacking}}
		{sort {threating}}
		{sort distance}
	}
	{group
		{select {class armoredcar}}
		{sort {attacking}}
		{sort distance}
	}
	{group
		{sort {weapon "rocketlauncher ap"} {attacking}}
		{sort {weapon "rocketlauncher ap"} {threating}}
		{sort distance}
	}
	
	{group
		{sort {weapon "at_rifle ap"} {attacking}}
		{sort {weapon "at_rifle ap"} {threating}}
		{sort distance}
	}
	{group
		{select {class car_bullet} {weapon}}
		{sort {attacking}}
		{sort distance}
	}
	{group
		{sort {class cannon_bullet}}
		{sort {class human} {weapon}}
		{sort {class human}}
		{sort distance}
	}
	{group
		{select {class car}}
		{sort distance}
	}
	{group
		{sort {attacking}}
		{sort distance}
	}
}