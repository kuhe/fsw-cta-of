{selector
	{type "cannon_aa"}

	{group
		{select {class airborne}}
		{sort distance}
	}
	{group
		{ignore {class airborne}}
		{sort {class tank_heavy}}
		{sort {class tank_medium}}
		{sort {class tank_light}}
		{sort {attacking}}
		{sort {threating}}
		{sort distance}
	}
	{group
		{select {class armoredcar}}
		{select {class car_cannon}}
		{select {class tank_bullet}}
		{sort {attacking}}
		{sort distance}
	}
	{group
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_small}}
		{sort {class cannon_zenite}}
		{sort {class cannon_bullet}}
		{sort distance}
	}
	{group
		{select {class car_bullet}}
		{select {class car}}
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
		{sort {class human} {weapon}}
		{sort {class human}}
		{sort distance}
	}
	{group
		{sort {attacking}}
		{sort distance}
	}
}
