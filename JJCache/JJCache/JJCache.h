//
//  JJCache.h
//  JJCache
//
//  Created by melot on 2021/2/19.
//

#import <Foundation/Foundation.h>

#if __has_include(<JJCache/JJCache.h>)
#import <JJCache/JJMemoryCache.h>
#import <JJCache/JJDiskCache.h>
#import <JJCache/JJKVStorage.h>
#else
#import "JJMemoryCache.h"
#import "JJDiskCache.h"
#import "JJKVStorage.h"
#endif

NS_ASSUME_NONNULL_BEGIN


@interface JJCache : NSObject

@property (copy, readonly) NSString *name;

/** The underlying memory cache. see `YYMemoryCache` for more information.*/
@property (strong, readonly) JJMemoryCache *memoryCache;

/** The underlying disk cache. see `YYDiskCache` for more information.*/
@property (strong, readonly) JJDiskCache *diskCache;

- (nullable instancetype)initWithName:(NSString *)name;

- (nullable instancetype)initWithPath:(NSString *)path NS_DESIGNATED_INITIALIZER;

+ (nullable instancetype)cacheWithName:(NSString *)name;

+ (nullable instancetype)cacheWithPath:(NSString *)path;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;


//MARK: - Access Methods

- (BOOL)containsObjectForKey:(NSString *)key;

- (void)containsObjectForKey:(NSString *)key withBlock:(nullable void(^)(NSString *key, BOOL contains))block;

- (nullable id<NSCoding>)objectForKey:(NSString *)key;

- (void)objectForKey:(NSString *)key withBlock:(nullable void(^)(NSString *key, id<NSCoding> object))block;

- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key;

- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key withBlock:(nullable void(^)(void))block;

- (void)removeObjectForKey:(NSString *)key;

- (void)removeObjectForKey:(NSString *)key withBlock:(nullable void(^)(NSString *key))block;

- (void)removeAllObjects;

- (void)removeAllObjectsWithBlock:(void(^)(void))block;

- (void)removeAllObjectsWithProgressBlock:(nullable void(^)(int removedCount, int totalCount))progress
                                 endBlock:(nullable void(^)(BOOL error))end;

@end

NS_ASSUME_NONNULL_END
