//
//  JJDiskCache.m
//  JJCache
//
//  Created by melot on 2021/2/19.
//

#import "JJDiskCache.h"

@implementation JJDiskCache


- (instancetype)init {
    @throw [NSException exceptionWithName:@"JJDiskCache init error" reason:@"JJDiskCache must be initialized with a path. Use 'initWithPath:' or 'initWithPath:inlineThreshold:' instead." userInfo:nil];
    return [self initWithPath:@""];
}

- (instancetype)initWithPath:(NSString *)path {
    return [self initWithPath:path inlineThreshold:0];
}

- (instancetype)initWithPath:(NSString *)path inlineThreshold:(NSUInteger)threshold {
    self = [super init];
    if (self) {
        
    }
    return self;
}


- (BOOL)containsObjectForKey:(NSString *)key {
    return NO;
}

- (BOOL)containsObjectForKey:(NSString *)key withBlock:(void(^)(NSString *key, BOOL contains))block {
    return NO;
}

- (void)setObject:(id<NSCoding>)object forKey:(NSString *)key {
    if (!key) return;
    if (!object) {
        [self removeObjectForKey:key];
        return;
    }
    
}

- (void)setObject:(id<NSCoding>)object forKey:(NSString *)key withBlock:(void(^)(void))block {
    
    
}

- (id<NSCoding>)objectForKey:(NSString *)key {
    return [self objectForKey:key withBlock:nil];
}

- (id<NSCoding>)objectForKey:(NSString *)key withBlock:(void(^)(void))block {
    
    return nil;
}

- (void)removeObjectForKey:(NSString *)key {
    [self removeObjectForKey:key withBlock:nil];
}

- (void)removeObjectForKey:(NSString *)key withBlock:(void(^)(NSString *key))block {
    
}

- (void)removeAllObjects {
    [self removeAllObjectsWithBlock:nil];
}

- (void)removeAllObjectsWithBlock:(void(^)(NSString *key))block {
    
}

@end
