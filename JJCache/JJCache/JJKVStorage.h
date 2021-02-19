//
//  JJKVStorage.h
//  JJCache
//
//  Created by melot on 2021/2/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JJKVStorageItem : NSObject

@property (nonatomic, copy) NSString *key;
@property (nonatomic, strong) NSData *value;
@property (nonatomic, copy, nullable) NSString *filename;
@property (nonatomic) int size;
@property (nonatomic) int modTime;
@property (nonatomic) int accessTime;
@property (nonatomic, strong, nullable) NSData *extendedData;

@end


typedef NS_ENUM(NSUInteger, JJKVStorageType) {
    JJKVStorageTypeFile,
    JJKVStorageTypeSQLite,
    /// 存储类型取决于选择
    JJKVStorageTypeMixed,
};


@interface JJKVStorage : NSObject

@property (nonatomic, readonly) NSString *path;        ///< The path of this storage.
@property (nonatomic, readonly) JJKVStorageType type;  ///< The type of this storage.
@property (nonatomic) BOOL errorLogsEnabled;           ///< Set `YES` to enable error logs for debug.

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

- (instancetype)initWithPath:(NSString *)path type:(JJKVStorageType)type NS_DESIGNATED_INITIALIZER;


//MARK: - Save Items

- (BOOL)saveItem:(JJKVStorageItem *)item;

- (BOOL)saveItemWithKey:(NSString *)key value:(NSData *)value;

- (BOOL)saveItemWithKey:(NSString *)key
                  value:(NSData *)value
               filename:(nullable NSString *)filename
           extendedData:(nullable NSData *)extendedData;


//MARK: - Remove Items

- (BOOL)removeItemForKey:(NSString *)key;

- (BOOL)removeItemForKeys:(NSArray<NSString *> *)keys;

- (BOOL)removeItemsLargerThanSize:(int)size;

- (BOOL)removeItemsEarlierThanTime:(int)time;

- (BOOL)removeItemsToFitSize:(int)maxSize;

- (BOOL)removeItemsToFitCount:(int)maxCount;

- (BOOL)removeAllItems;

- (void)removeAllItemsWithProgressBlock:(nullable void(^)(int removedCount, int totalCount))progress
                               endBlock:(nullable void(^)(BOOL error))end;


//MARK: - Get Items

- (nullable JJKVStorageItem *)getItemForKey:(NSString *)key;

- (nullable JJKVStorageItem *)getItemInfoForKey:(NSString *)key;

- (nullable NSData *)getItemValueForKey:(NSString *)key;

- (nullable NSArray<JJKVStorageItem *> *)getItemForKeys:(NSArray<NSString *> *)keys;

- (nullable NSArray<JJKVStorageItem *> *)getItemInfoForKeys:(NSArray<NSString *> *)keys;

- (nullable NSDictionary<NSString *, NSData *> *)getItemValueForKeys:(NSArray<NSString *> *)keys;


//MARK: - Get Storage Status

- (BOOL)itemExistsForKey:(NSString *)key;

- (int)getItemsCount;

- (int)getItemsSize;

@end

NS_ASSUME_NONNULL_END
