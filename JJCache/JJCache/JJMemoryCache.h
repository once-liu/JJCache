//
//  JJMemoryCache.h
//  JJCache
//
//  Created by melot on 2021/2/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JJMemoryCache : NSObject

@property (nullable, copy) NSString *name;

@property (readonly) NSUInteger totalCount;

@property (readonly) NSUInteger totalCost;


//MARK: - Limit

@property NSUInteger costLimit;

@property NSUInteger countLimit;

@property NSTimeInterval ageLimit;

@property NSTimeInterval autoTrimInterval;

@property BOOL shouldRemoveAllObjectsOnMemoryWarning;

@property BOOL shouldRemoveAllObjectsWhenEnteringBackground;

@property (nonatomic, copy) void(^didReceiveMemoryWarningBlock)(JJMemoryCache *cache);

@property (nonatomic, copy) void(^didEnterBackgroundBlock)(JJMemoryCache *cache);

@property BOOL releaseOnMainThread;

@property BOOL releaseAsynchronously;


//MARK: - Access Methods

- (BOOL)containsObjectForKey:(id)key;

- (nullable id)objectForKey:(id)key;

- (void)setObject:(nullable id)object forKey:(id)key;

- (void)setObject:(nullable id)object forKey:(id)key withCost:(NSUInteger)cost;

- (void)removeObjectForKey:(id)key;

- (void)removeAllObjects;


//MARK: - Trim

- (void)trimToCount:(NSUInteger)count;

- (void)trimToCost:(NSUInteger)cost;

- (void)trimToAge:(NSTimeInterval)age;


@end

NS_ASSUME_NONNULL_END
