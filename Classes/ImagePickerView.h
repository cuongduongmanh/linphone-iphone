/*
 * Copyright (c) 2010-2020 Belledonne Communications SARL.
 *
 * This file is part of linphone-iphone 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#import "UICompositeView.h"

@protocol ImagePickerDelegate <NSObject>

- (void)imagePickerDelegateImage:(UIImage *)image info:(NSString *)phAssetId;
- (void)imagePickerDelegateVideo:(NSURL*)url info:(NSDictionary *)info;
@end

@interface ImagePickerView : UIViewController <UICompositeViewDelegate, UINavigationControllerDelegate,
											   UIImagePickerControllerDelegate, UIPopoverControllerDelegate> {
  @private
	UIImagePickerController *pickerController;
}

@property(nonatomic, strong) id<ImagePickerDelegate> imagePickerDelegate;
@property(nonatomic) UIImagePickerControllerSourceType sourceType;
@property(nonatomic, copy) NSArray *mediaTypes;
@property(nonatomic) BOOL allowsEditing;
@property(nonatomic, readonly) UIPopoverController *popoverController;

+ (void)SelectImageFromDevice:(id<ImagePickerDelegate>)delegate
				   atPosition:(UIView *)ipadPopoverView
					   inView:(UIView *)ipadView
	 withDocumentMenuDelegate:(id<UIDocumentMenuDelegate>)documentMenuDelegate;

@end
