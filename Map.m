//
//  Map.m
//  TrenchBroom
//
//  Created by Kristian Duske on 15.03.10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "Map.h"
#import "Entity.h"
#import "Brush.h"

NSString* const MapEntityAdded = @"EntityAdded";
NSString* const MapEntityRemoved = @"EntityRemoved";

NSString* const MapEntity = @"Entity";

@implementation Map

- (id)init {
    if (self = [super init]) {
        entities = [[NSMutableSet alloc] init];
        worldspawn = nil;
    }
    
    return self;
}

- (Entity *)worldspawn {
    if (worldspawn == nil || ![worldspawn isWorldspawn]) {
        NSEnumerator* en = [entities objectEnumerator];
        while ((worldspawn = [en nextObject]))
            if ([worldspawn isWorldspawn])
                break;
    }
    
    return worldspawn;
}

- (Entity *)createEntity {
    Entity* entity = [[Entity alloc] init];
    [entities addObject:entity];
    
    NSMutableDictionary* info = [NSMutableDictionary dictionaryWithCapacity:1];
    [info setObject:entity forKey:MapEntity];
    
    [[NSNotificationCenter defaultCenter] postNotificationName:MapEntityAdded object:self userInfo:info];
    return [entity autorelease];
}

- (Entity *)createEntityWithProperty:(NSString *)key value:(NSString *)value {
    Entity* entity = [[Entity alloc] initWithProperty:key value:value];
    [entities addObject:entity];

    NSMutableDictionary* info = [NSMutableDictionary dictionaryWithCapacity:1];
    [info setObject:entity forKey:MapEntity];
    
    [[NSNotificationCenter defaultCenter] postNotificationName:MapEntityAdded object:self userInfo:info];
    return [entity autorelease];
}

- (void)removeEntity:(Entity *)entity {
    [entities removeObject:entity];

    NSMutableDictionary* info = [NSMutableDictionary dictionaryWithCapacity:1];
    [info setObject:entity forKey:MapEntity];
    
    [[NSNotificationCenter defaultCenter] postNotificationName:MapEntityRemoved object:self userInfo:info];
}

- (NSSet *)entities {
    return entities;
}

- (void)dealloc {
    [entities release];
    
    [super dealloc];
}

@end
