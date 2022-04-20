import { FileSystemStoredFile, HasMimeType, IsFile, MaxFileSize } from 'nestjs-form-data';


export class AvatarDto {

  @IsFile()
  @HasMimeType(['image/jpeg', 'image/png'])
  avatar: FileSystemStoredFile;

}