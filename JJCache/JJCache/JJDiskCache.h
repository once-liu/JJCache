//
//  JJDiskCache.h
//  JJCache
//
//  Created by melot on 2021/2/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JJDiskCache : NSObject

/** The name of the cache. Default is nil. */
@property (nullable, copy) NSString *name;

/** The path of the cache (read-only). */
@property (readonly) NSString *path;

/**
 If the object's data size (in bytes) is larger than this value, then object will
 be stored as a file, otherwise the object will be stored in sqlite.
 
 0 means all objects will be stored as separated files, NSUIntegerMax means all
 objects will be stored in sqlite.
 
 The default value is 20480 (20KB).
 */
@property (readonly) NSUInteger inlineThreshold;


@property (nullable, copy) NSData *(^customArchiveBlock)(id object);

@property (nullable, copy) id (^customUnarchiveBlock)(NSData *data);

@property (nullable, copy) NSString *(^customFileNameBlock)(NSString *key);


//MARK: - Initlizer

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

- (nullable instancetype)initWithPath:(NSString *)path;

- (nullable instancetype)initWithPath:(NSString *)path
                      inlineThreshold:(NSUInteger)threshold NS_DESIGNATED_INITIALIZER;


//MARK: - Limit

@property NSUInteger countLimit;

@property NSUInteger costLimit;

@property NSTimeInterval ageLimit;

@property NSUInteger freeDiskSpaceLimit;

@property NSTimeInterval autoTrimInterval;

@property BOOL errorLogsEnabled;


//MARK: - Access Methods

- (BOOL)containsObjectForKey:(NSString *)key;

- (void)containsObjectForKey:(NSString *)key withBlock:(void(^)(NSString *key, BOOL contains))block;

- (nullable id<NSCoding>)objectForKey:(NSString *)key;

- (void)objectForKey:(NSString *)key withBlock:(void(^)(NSString *key, id<NSCoding> _Nullable object))block;

- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key;

- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key withBlock:(void(^)(void))block;

- (void)removeObjectForKey:(NSString *)key;

- (void)removeObjectForKey:(NSString *)key withBlock:(void(^)(NSString *key))block;

- (void)removeAllObjects;

- (void)removeAllObjectsWithBlock:(void(^)(void))block;

- (void)removeAllObjectsWithProgressBlock:(nullable void(^)(int removedCount, int totalCount))progress
                                 endBlock:(nullable void(^)(BOOL error))end;

- (NSInteger)totalCount;

- (void)totalCountWithBlock:(void(^)(NSInteger totalCount))block;

- (NSInteger)totalCost;

- (void)totalCostWithBlock:(void(^)(NSInteger totalCost))block;


//MARK: - Trim

- (void)trimToCount:(NSUInteger)count;

- (void)trimToCount:(NSUInteger)count withBlock:(void(^)(void))block;

- (void)trimToCost:(NSUInteger)cost;

- (void)trimToCost:(NSUInteger)cost withBlock:(void(^)(void))block;

- (void)trimToAge:(NSTimeInterval)age;

- (void)trimToAge:(NSTimeInterval)age withBlock:(void(^)(void))block;


//MARK: - Extended Data

+ (nullable NSData *)getExtendedDataFromObject:(id)object;

+ (void)setExtendedData:(nullable NSData *)extendedData toObject:(id)object;

@end

NS_ASSUME_NONNULL_END
